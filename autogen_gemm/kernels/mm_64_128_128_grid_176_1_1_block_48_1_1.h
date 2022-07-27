
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
extern "C" __global__ void __launch_bounds__(48)
    mm_64_128_128(float* __restrict__ A, float* __restrict__ B,
                  float* __restrict__ compute) {
  float compute_local[1];
  __shared__ float A_shared[128];
  __shared__ float B_shared[384];
  float A_shared_local[1];
  float B_shared_local[1];
  compute_local[(0)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 4; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] = A[((((((((int)blockIdx.x) / 11) * 512) +
                                           ((((int)threadIdx.x) >> 5) * 128)) +
                                          (k_outer * 32)) +
                                         (((int)threadIdx.x) & 31)))];
    A_shared[((((int)threadIdx.x) + 48))] =
        A[((((((((int)blockIdx.x) / 11) * 512) +
              (((((int)threadIdx.x) + 48) >> 5) * 128)) +
             (k_outer * 32)) +
            ((((int)threadIdx.x) + 16) & 31)))];
    if (((int)threadIdx.x) < 32) {
      A_shared[((((int)threadIdx.x) + 96))] =
          A[((((((((int)blockIdx.x) / 11) * 512) + (k_outer * 32)) +
               ((int)threadIdx.x)) +
              384))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[(((int)threadIdx.x))] =
          B[(((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
               ((((int)blockIdx.x) % 11) * 12)) +
              (((int)threadIdx.x) % 12)))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 48))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              512))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 96))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              1024))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 144))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              1536))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 192))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              2048))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 240))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              2560))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 288))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              3072))];
    }
    if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
      B_shared[((((int)threadIdx.x) + 336))] =
          B[((((((k_outer * 4096) + ((((int)threadIdx.x) / 12) * 128)) +
                ((((int)blockIdx.x) % 11) * 12)) +
               (((int)threadIdx.x) % 12)) +
              3584))];
    }
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 32; ++k_inner_outer) {
      A_shared_local[(0)] =
          A_shared[((((((int)threadIdx.x) / 12) * 32) + k_inner_outer))];
      if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
        B_shared_local[(0)] =
            B_shared[(((k_inner_outer * 12) + (((int)threadIdx.x) % 12)))];
      }
      if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
        compute_local[(0)] =
            (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
      }
    }
  }
  if ((((((int)blockIdx.x) % 11) * 12) + (((int)threadIdx.x) % 12)) < 128) {
    compute[((((((((int)blockIdx.x) / 11) * 512) +
                ((((int)threadIdx.x) / 12) * 128)) +
               ((((int)blockIdx.x) % 11) * 12)) +
              (((int)threadIdx.x) % 12)))] = compute_local[(0)];
  }
}
