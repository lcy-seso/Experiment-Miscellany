#pragma once

#include <map>

typedef void (*KernelFunc)(float*, float*, float*);

typedef struct KernelFuncInfo {
  int m;
  int n;
  int k;
  const KernelFunc func;
  const dim3* grid;
  const dim3* block;

 public:
  KernelFuncInfo(int m, int n, int k, KernelFunc f, dim3* g, dim3* b)
      : m(m), n(n), k(k), func(f), grid(g), block(b) {}
} KernelFuncInfo;

typedef std::map<std::string, KernelFuncInfo> KernelFuncMap;
KernelFuncMap kernelMap;

namespace {
template <typename T>
__global__ void naiveFillKernel(T* data, int num, T value) {
  int tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < num) data[tid] = value;
}
}  // namespace

void fillZeros(float* data, int numel, float val = 0.) {
  int block = 512;
  int grid = (numel + block - 1) / block;

  naiveFillKernel<float><<<grid, block>>>(data, numel, val);
}
