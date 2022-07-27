
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
extern "C" __global__ void __launch_bounds__(128)
    mm_512_64_64(float* __restrict__ A, float* __restrict__ B,
                 float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[1024];
  __shared__ float B_shared[256];
  float A_shared_local[2];
  float B_shared_local[1];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 2; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] = A[((((((((int)blockIdx.x) >> 3) * 2048) +
                                           ((((int)threadIdx.x) >> 5) * 64)) +
                                          (k_outer * 32)) +
                                         (((int)threadIdx.x) & 31)))];
    A_shared[((((int)threadIdx.x) + 128))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            256))];
    A_shared[((((int)threadIdx.x) + 256))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            512))];
    A_shared[((((int)threadIdx.x) + 384))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            768))];
    A_shared[((((int)threadIdx.x) + 512))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            1024))];
    A_shared[((((int)threadIdx.x) + 640))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            1280))];
    A_shared[((((int)threadIdx.x) + 768))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            1536))];
    A_shared[((((int)threadIdx.x) + 896))] =
        A[(((((((((int)blockIdx.x) >> 3) * 2048) +
               ((((int)threadIdx.x) >> 5) * 64)) +
              (k_outer * 32)) +
             (((int)threadIdx.x) & 31)) +
            1792))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 2048) + ((((int)threadIdx.x) >> 3) * 64)) +
             ((((int)blockIdx.x) & 7) * 8)) +
            (((int)threadIdx.x) & 7)))];
    B_shared[((((int)threadIdx.x) + 128))] =
        B[((((((k_outer * 2048) + ((((int)threadIdx.x) >> 3) * 64)) +
              ((((int)blockIdx.x) & 7) * 8)) +
             (((int)threadIdx.x) & 7)) +
            1024))];
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 32; ++k_inner_outer) {
      A_shared_local[(0)] =
          A_shared[((((((int)threadIdx.x) >> 3) * 32) + k_inner_outer))];
      A_shared_local[(1)] = A_shared[(
          ((((((int)threadIdx.x) >> 3) * 32) + k_inner_outer) + 512))];
      B_shared_local[(0)] =
          B_shared[(((k_inner_outer * 8) + (((int)threadIdx.x) & 7)))];
      compute_local[(0)] =
          (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
      compute_local[(1)] =
          (compute_local[(1)] + (A_shared_local[(1)] * B_shared_local[(0)]));
    }
  }
  compute[(
      (((((((int)blockIdx.x) >> 3) * 2048) + ((((int)threadIdx.x) >> 3) * 64)) +
        ((((int)blockIdx.x) & 7) * 8)) +
       (((int)threadIdx.x) & 7)))] = compute_local[(0)];
  compute[((
      (((((((int)blockIdx.x) >> 3) * 2048) + ((((int)threadIdx.x) >> 3) * 64)) +
        ((((int)blockIdx.x) & 7) * 8)) +
       (((int)threadIdx.x) & 7)) +
      1024))] = compute_local[(1)];
}
