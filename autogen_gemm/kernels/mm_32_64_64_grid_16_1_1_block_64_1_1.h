
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
extern "C" __global__ void __launch_bounds__(64)
    mm_32_64_64(float* __restrict__ A, float* __restrict__ B,
                float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[256];
  __shared__ float B_shared[2048];
  float A_shared_local[1];
  float B_shared_local[2];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  A_shared[(((int)threadIdx.x))] =
      A[((((((int)blockIdx.x) >> 1) * 256) + ((int)threadIdx.x)))];
  A_shared[((((int)threadIdx.x) + 64))] =
      A[(((((((int)blockIdx.x) >> 1) * 256) + ((int)threadIdx.x)) + 64))];
  A_shared[((((int)threadIdx.x) + 128))] =
      A[(((((((int)blockIdx.x) >> 1) * 256) + ((int)threadIdx.x)) + 128))];
  A_shared[((((int)threadIdx.x) + 192))] =
      A[(((((((int)blockIdx.x) >> 1) * 256) + ((int)threadIdx.x)) + 192))];
  B_shared[(((int)threadIdx.x))] =
      B[(((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
          (((int)threadIdx.x) & 31)))];
  B_shared[((((int)threadIdx.x) + 64))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          128))];
  B_shared[((((int)threadIdx.x) + 128))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          256))];
  B_shared[((((int)threadIdx.x) + 192))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          384))];
  B_shared[((((int)threadIdx.x) + 256))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          512))];
  B_shared[((((int)threadIdx.x) + 320))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          640))];
  B_shared[((((int)threadIdx.x) + 384))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          768))];
  B_shared[((((int)threadIdx.x) + 448))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          896))];
  B_shared[((((int)threadIdx.x) + 512))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1024))];
  B_shared[((((int)threadIdx.x) + 576))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1152))];
  B_shared[((((int)threadIdx.x) + 640))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1280))];
  B_shared[((((int)threadIdx.x) + 704))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1408))];
  B_shared[((((int)threadIdx.x) + 768))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1536))];
  B_shared[((((int)threadIdx.x) + 832))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1664))];
  B_shared[((((int)threadIdx.x) + 896))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1792))];
  B_shared[((((int)threadIdx.x) + 960))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          1920))];
  B_shared[((((int)threadIdx.x) + 1024))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2048))];
  B_shared[((((int)threadIdx.x) + 1088))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2176))];
  B_shared[((((int)threadIdx.x) + 1152))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2304))];
  B_shared[((((int)threadIdx.x) + 1216))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2432))];
  B_shared[((((int)threadIdx.x) + 1280))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2560))];
  B_shared[((((int)threadIdx.x) + 1344))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2688))];
  B_shared[((((int)threadIdx.x) + 1408))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2816))];
  B_shared[((((int)threadIdx.x) + 1472))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          2944))];
  B_shared[((((int)threadIdx.x) + 1536))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3072))];
  B_shared[((((int)threadIdx.x) + 1600))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3200))];
  B_shared[((((int)threadIdx.x) + 1664))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3328))];
  B_shared[((((int)threadIdx.x) + 1728))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3456))];
  B_shared[((((int)threadIdx.x) + 1792))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3584))];
  B_shared[((((int)threadIdx.x) + 1856))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3712))];
  B_shared[((((int)threadIdx.x) + 1920))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3840))];
  B_shared[((((int)threadIdx.x) + 1984))] =
      B[((((((((int)threadIdx.x) >> 5) * 64) + ((((int)blockIdx.x) & 1) * 32)) +
           (((int)threadIdx.x) & 31)) +
          3968))];
  __syncthreads();
  for (int k_inner_outer = 0; k_inner_outer < 64; ++k_inner_outer) {
    A_shared_local[(0)] =
        A_shared[((((((int)threadIdx.x) >> 4) * 64) + k_inner_outer))];
    B_shared_local[(0)] =
        B_shared[(((k_inner_outer * 32) + (((int)threadIdx.x) & 15)))];
    B_shared_local[(1)] =
        B_shared[((((k_inner_outer * 32) + (((int)threadIdx.x) & 15)) + 16))];
    compute_local[(0)] =
        (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
    compute_local[(1)] =
        (compute_local[(1)] + (A_shared_local[(0)] * B_shared_local[(1)]));
  }
  compute[(
      (((((((int)blockIdx.x) >> 1) * 256) + ((((int)threadIdx.x) >> 4) * 64)) +
        ((((int)blockIdx.x) & 1) * 32)) +
       (((int)threadIdx.x) & 15)))] = compute_local[(0)];
  compute[(
      ((((((((int)blockIdx.x) >> 1) * 256) + ((((int)threadIdx.x) >> 4) * 64)) +
         ((((int)blockIdx.x) & 1) * 32)) +
        (((int)threadIdx.x) & 15)) +
       16))] = compute_local[(1)];
}
