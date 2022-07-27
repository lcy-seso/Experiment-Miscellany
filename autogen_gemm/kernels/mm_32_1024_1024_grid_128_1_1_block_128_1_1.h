
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
    mm_32_1024_1024(float* __restrict__ A, float* __restrict__ B,
                    float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[1024];
  __shared__ float B_shared[4096];
  float A_shared_local[1];
  float B_shared_local[2];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 8; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] =
        A[(((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
            ((int)threadIdx.x)))];
    A_shared[((((int)threadIdx.x) + 128))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            1024))];
    A_shared[((((int)threadIdx.x) + 256))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            2048))];
    A_shared[((((int)threadIdx.x) + 384))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            3072))];
    A_shared[((((int)threadIdx.x) + 512))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            4096))];
    A_shared[((((int)threadIdx.x) + 640))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            5120))];
    A_shared[((((int)threadIdx.x) + 768))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            6144))];
    A_shared[((((int)threadIdx.x) + 896))] =
        A[((((((((int)blockIdx.x) >> 5) * 8192) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            7168))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
             ((((int)blockIdx.x) & 31) * 32)) +
            (((int)threadIdx.x) & 31)))];
    B_shared[((((int)threadIdx.x) + 128))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            4096))];
    B_shared[((((int)threadIdx.x) + 256))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            8192))];
    B_shared[((((int)threadIdx.x) + 384))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            12288))];
    B_shared[((((int)threadIdx.x) + 512))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))];
    B_shared[((((int)threadIdx.x) + 640))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            20480))];
    B_shared[((((int)threadIdx.x) + 768))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            24576))];
    B_shared[((((int)threadIdx.x) + 896))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            28672))];
    B_shared[((((int)threadIdx.x) + 1024))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            32768))];
    B_shared[((((int)threadIdx.x) + 1152))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            36864))];
    B_shared[((((int)threadIdx.x) + 1280))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            40960))];
    B_shared[((((int)threadIdx.x) + 1408))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            45056))];
    B_shared[((((int)threadIdx.x) + 1536))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            49152))];
    B_shared[((((int)threadIdx.x) + 1664))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            53248))];
    B_shared[((((int)threadIdx.x) + 1792))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            57344))];
    B_shared[((((int)threadIdx.x) + 1920))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            61440))];
    B_shared[((((int)threadIdx.x) + 2048))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            65536))];
    B_shared[((((int)threadIdx.x) + 2176))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            69632))];
    B_shared[((((int)threadIdx.x) + 2304))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            73728))];
    B_shared[((((int)threadIdx.x) + 2432))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            77824))];
    B_shared[((((int)threadIdx.x) + 2560))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            81920))];
    B_shared[((((int)threadIdx.x) + 2688))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            86016))];
    B_shared[((((int)threadIdx.x) + 2816))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            90112))];
    B_shared[((((int)threadIdx.x) + 2944))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            94208))];
    B_shared[((((int)threadIdx.x) + 3072))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            98304))];
    B_shared[((((int)threadIdx.x) + 3200))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            102400))];
    B_shared[((((int)threadIdx.x) + 3328))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            106496))];
    B_shared[((((int)threadIdx.x) + 3456))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            110592))];
    B_shared[((((int)threadIdx.x) + 3584))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            114688))];
    B_shared[((((int)threadIdx.x) + 3712))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            118784))];
    B_shared[((((int)threadIdx.x) + 3840))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            122880))];
    B_shared[((((int)threadIdx.x) + 3968))] =
        B[((((((k_outer * 131072) + ((((int)threadIdx.x) >> 5) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 31)) +
            126976))];
    __syncthreads();
    for (int k_inner_outer = 0; k_inner_outer < 128; ++k_inner_outer) {
      A_shared_local[(0)] =
          A_shared[((((((int)threadIdx.x) >> 4) * 128) + k_inner_outer))];
      B_shared_local[(0)] =
          B_shared[(((k_inner_outer * 32) + (((int)threadIdx.x) & 15)))];
      B_shared_local[(1)] =
          B_shared[((((k_inner_outer * 32) + (((int)threadIdx.x) & 15)) + 16))];
      compute_local[(0)] =
          (compute_local[(0)] + (A_shared_local[(0)] * B_shared_local[(0)]));
      compute_local[(1)] =
          (compute_local[(1)] + (A_shared_local[(0)] * B_shared_local[(1)]));
    }
  }
  compute[((((((((int)blockIdx.x) >> 5) * 8192) +
              ((((int)threadIdx.x) >> 4) * 1024)) +
             ((((int)blockIdx.x) & 31) * 32)) +
            (((int)threadIdx.x) & 15)))] = compute_local[(0)];
  compute[(((((((((int)blockIdx.x) >> 5) * 8192) +
               ((((int)threadIdx.x) >> 4) * 1024)) +
              ((((int)blockIdx.x) & 31) * 32)) +
             (((int)threadIdx.x) & 15)) +
            16))] = compute_local[(1)];
}
