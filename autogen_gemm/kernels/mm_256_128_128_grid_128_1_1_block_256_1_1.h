
#ifdef _WIN32
using uint = unsigned int;
using uchar = unsigned char;
using ushort = unsigned short;
using int64_t = long long;
using uint64_t = unsigned long long;
#else
#define uint unsigned int
#define uchar unsigned char
#define ushort unsigned short
#define int64_t long long
#define uint64_t unsigned long long
#endif
extern "C" __global__ void __launch_bounds__(256)
    mm_256_128_128(float* __restrict__ A, float* __restrict__ B,
                   float* __restrict__ compute) {
  float compute_local[1];
  __shared__ float A_shared[512];
  __shared__ float B_shared[512];
  float A_shared_local[1];
  float B_shared_local[1];
  compute_local[(0)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 4; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] = A[((((((((int)blockIdx.x) >> 3) * 2048) +
                                           ((((int)threadIdx.x) >> 5) * 128)) +
                                          (k_outer * 32)) +
                                         (((int)threadIdx.x) & 31)))];
    A_shared[((((int)threadIdx.x) + 256))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 128)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            1024))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 4096) + ((((int)threadIdx.x) >> 4) * 128)) +
             ((((int)blockIdx.x) & 7) * 16)) +
            (((int)threadIdx.x) & 15)))];
    B_shared[((((int)threadIdx.x) + 256))] =
        B[((((((k_outer * 4096) + ((((int)threadIdx.x) >> 4) * 128)) +
              ((((int)blockIdx.x) & 7) * 16)) +
             (((int)threadIdx.x) & 15)) +
            2048))];
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 32; ++k_inner_outer) {
      A_shared_local[(0)] =
          A_shared[((((((int)threadIdx.x) >> 4) * 32) + k_inner_outer))];
      B_shared_local[(0)] =
          B_shared[(((k_inner_outer * 16) + (((int)threadIdx.x) & 15)))];
      compute_local[(0)] =
          (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
    }
  }
  compute[((
      ((((((int)blockIdx.x) >> 3) * 2048) + ((((int)threadIdx.x) >> 4) * 128)) +
       ((((int)blockIdx.x) & 7) * 16)) +
      (((int)threadIdx.x) & 15)))] = compute_local[(0)];
}
