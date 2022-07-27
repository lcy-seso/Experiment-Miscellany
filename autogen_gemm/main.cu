#include <assert.h>
#include <cublas_v2.h>
#include <cuda_runtime_api.h>
#include <curand.h>

#include <iomanip>
#include <iostream>
#include <vector>

#include "kernels/generated_kernels.h"
#include "kernels/kernel_func_def.h"
#include "utils.h"

#define cudaErrCheck(stat) \
  { cudaErrCheck_((stat), __FILE__, __LINE__); }
void cudaErrCheck_(cudaError_t stat, const char* file, int line) {
  if (stat != cudaSuccess) {
    fprintf(stderr, "CUDA Error: %s %s %d\n", cudaGetErrorString(stat), file,
            line);
  }
}

void fillRandom(float* A, int elementNum) {
  // create a pseudo-random number generator
  curandGenerator_t prng;
  curandCreateGenerator(&prng, CURAND_RNG_PSEUDO_DEFAULT);

  // set the seed for the random number generator using the system clock
  curandSetPseudoRandomGeneratorSeed(prng, (unsigned long long)clock());

  // fill the array with random numbers on the device
  curandGenerateUniform(prng, A, elementNum);
}

void checkResults(const float* C1, const float* C2, int numel) {
  float* C1_cpu = (float*)malloc(numel * sizeof(float));
  float* C2_cpu = (float*)malloc(numel * sizeof(float));
  cudaMemcpy(C1_cpu, C1, numel * sizeof(float), cudaMemcpyDeviceToHost);
  cudaMemcpy(C2_cpu, C2, numel * sizeof(float), cudaMemcpyDeviceToHost);

  for (int i = 0; i < numel; ++i) {
    std::cout << C1_cpu[i] << std::endl;
  }

  free(C1_cpu);
  free(C2_cpu);
}

void createData(int m, int n, int k, float* d_A, float* d_B, float* d_C1,
                float* d_C2) {
  int64_t size_A = m * k;
  int64_t size_B = k * n;
  int64_t size_C = m * n;

  cudaMalloc(&d_A, size_A * sizeof(float));
  cudaMalloc(&d_B, size_B * sizeof(float));

  cudaMalloc(&d_C1, size_C * sizeof(float));
  cudaMalloc(&d_C2, size_C * sizeof(float));

  fillRandom(d_A, size_A);
  fillRandom(d_B, size_B);
  fillZeros(d_C1, size_C);
  fillZeros(d_C2, size_C);
}

void testAutoGenGemm(int m, int n, int k, dim3 grid, dim3 block,
                     KernelFunc func, std::vector<float>& info) {
  float* d_A = NULL;
  float* d_B = NULL;
  float* d_C1 = NULL;
  float* d_C2 = NULL;
  // allocate GPU memory
  createData(m, n, k, d_A, d_B, d_C1, d_C2);

  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  float total1 = 0.;
  float elapsed = 0.;
  int iters = 20;
  for (int i = 0; i < iters; ++i) {
    cudaEventRecord(start, 0);

    func<<<grid, block>>>(d_A, d_B, d_C1);

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&elapsed, start, stop);

    total1 += elapsed;
  }

  // CuBlas
  float total2 = 0.;
  float alf = 1.0, bet = 0.0;
  const float* alpha = &alf;
  const float* beta = &bet;
  elapsed = 0.;

  cublasHandle_t handle;
  // create cuBlas handler
  cublasCreate(&handle);
  cublasSgemm(handle, CUBLAS_OP_N /* transA */, CUBLAS_OP_N /* transB */, m, n,
              k, alpha, d_A, m, d_B, k, beta, d_C2, m);

  for (int i = 0; i < iters; ++i) {
    cudaEventRecord(start, 0);

    cublasSgemm(handle, CUBLAS_OP_N /* transA */, CUBLAS_OP_N /* transB */, m,
                n, k, alpha, d_A, m, d_B, k, beta, d_C2, m);

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    cudaEventElapsedTime(&elapsed, start, stop);
    total2 += elapsed;
  }

  checkResults(d_C1, d_C2, m * n);

  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C1);
  cudaFree(d_C2);

  info[0] = total1 / iters;
  info[1] = total2 / iters;
}

int main(int argc, char** argv) {
  createKernelInfoMap(kernelMap);

  std::cout.setf(std::ios::fixed);
  std::cout << std::setprecision(4);
  std::cout << "|[m, n, k]|Generated Kernels|cuBlas|" << std::endl
            << "|:--|:--|:--|" << std::endl;

  auto it = kernelMap.begin();
  while (it != kernelMap.end()) {
    std::vector<float> times(2, 0.);
    auto func = it->second;
    testAutoGenGemm(func.m, func.n, func.k, *(func.grid), *(func.block),
                    func.func, times);
    it++;

    std::cout << "[" << func.m << ", " << func.n << ", " << func.k << "]|"
              << times[0] << "|" << times[1] << "|" << std::endl;
  }

  return 0;
}
