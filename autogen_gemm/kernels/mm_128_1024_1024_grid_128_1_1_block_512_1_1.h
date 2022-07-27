
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
extern "C" __global__ void __launch_bounds__(512)
    mm_128_1024_1024(float* __restrict__ A, float* __restrict__ B,
                     float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[1024];
  __shared__ float B_shared[1024];
  float A_shared_local[2];
  float B_shared_local[1];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 32; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] = A[((((((((int)blockIdx.x) >> 5) * 32768) +
                                           ((((int)threadIdx.x) >> 5) * 1024)) +
                                          (k_outer * 32)) +
                                         (((int)threadIdx.x) & 31)))];
    A_shared[((((int)threadIdx.x) + 512))] =
        A[(((((((((int)blockIdx.x) >> 5) * 32768) +
               ((((int)threadIdx.x) >> 5) * 1024)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 1024)) +
             ((((int)blockIdx.x) & 31) * 32)) +
            (((int)threadIdx.x) & 31)))];
    B_shared[((((int)threadIdx.x) + 512))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))];
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 32; ++k_inner_outer) {
      A_shared_local[(0)] =
          A_shared[((((((int)threadIdx.x) >> 5) * 32) + k_inner_outer))];
      A_shared_local[(1)] = A_shared[(
          ((((((int)threadIdx.x) >> 5) * 32) + k_inner_outer) + 512))];
      B_shared_local[(0)] =
          B_shared[(((k_inner_outer * 32) + (((int)threadIdx.x) & 31)))];
      compute_local[(0)] =
          (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
      compute_local[(1)] =
          (compute_local[(1)] + (A_shared_local[(1)] * B_shared_local[(0)]));
    }
  }
  compute[((((((((int)blockIdx.x) >> 5) * 32768) +
              ((((int)threadIdx.x) >> 5) * 1024)) +
             ((((int)blockIdx.x) & 31) * 32)) +
            (((int)threadIdx.x) & 31)))] = compute_local[(0)];
  compute[(((((((((int)blockIdx.x) >> 5) * 32768) +
               ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))] = compute_local[(1)];
}
