
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
extern "C" __global__ void __launch_bounds__(96)
    mm_128_64_64(float* __restrict__ A, float* __restrict__ B,
                 float* __restrict__ compute) {
  float compute_local[1];
  __shared__ float A_shared[96];
  __shared__ float B_shared[64];
  float A_shared_local[1];
  float B_shared_local[1];
  compute_local[(0)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 8; ++k_outer) {
    __syncthreads();
    if ((((((int)blockIdx.x) >> 3) * 12) + (((int)threadIdx.x) >> 3)) < 128) {
      A_shared[(((int)threadIdx.x))] = A[((((((((int)blockIdx.x) >> 3) * 768) +
                                             ((((int)threadIdx.x) >> 3) * 64)) +
                                            (k_outer * 8)) +
                                           (((int)threadIdx.x) & 7)))];
    }
    if (((int)threadIdx.x) < 64) {
      B_shared[(((int)threadIdx.x))] =
          B[(((((k_outer * 512) + ((((int)threadIdx.x) >> 3) * 64)) +
               ((((int)blockIdx.x) & 7) * 8)) +
              (((int)threadIdx.x) & 7)))];
    }
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 8; ++k_inner_outer) {
      if ((((((int)blockIdx.x) >> 3) * 12) + (((int)threadIdx.x) >> 3)) < 128) {
        A_shared_local[(0)] =
            A_shared[((((((int)threadIdx.x) >> 3) * 8) + k_inner_outer))];
      }
      B_shared_local[(0)] =
          B_shared[(((k_inner_outer * 8) + (((int)threadIdx.x) & 7)))];
      if ((((((int)blockIdx.x) >> 3) * 12) + (((int)threadIdx.x) >> 3)) < 128) {
        compute_local[(0)] =
            (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
      }
    }
  }
  if ((((((int)blockIdx.x) >> 3) * 12) + (((int)threadIdx.x) >> 3)) < 128) {
    compute[((
        ((((((int)blockIdx.x) >> 3) * 768) + ((((int)threadIdx.x) >> 3) * 64)) +
         ((((int)blockIdx.x) & 7) * 8)) +
        (((int)threadIdx.x) & 7)))] = compute_local[(0)];
  }
}
