
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
    mm_32_512_512(float* __restrict__ A, float* __restrict__ B,
                  float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[1024];
  __shared__ float B_shared[4096];
  float A_shared_local[1];
  float B_shared_local[2];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 4; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] =
        A[(((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
            ((int)threadIdx.x)))];
    A_shared[((((int)threadIdx.x) + 128))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            512))];
    A_shared[((((int)threadIdx.x) + 256))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            1024))];
    A_shared[((((int)threadIdx.x) + 384))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            1536))];
    A_shared[((((int)threadIdx.x) + 512))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            2048))];
    A_shared[((((int)threadIdx.x) + 640))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            2560))];
    A_shared[((((int)threadIdx.x) + 768))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            3072))];
    A_shared[((((int)threadIdx.x) + 896))] =
        A[((((((((int)blockIdx.x) >> 4) * 4096) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            3584))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
             ((((int)blockIdx.x) & 15) * 32)) +
            (((int)threadIdx.x) & 31)))];
    B_shared[((((int)threadIdx.x) + 128))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            2048))];
    B_shared[((((int)threadIdx.x) + 256))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            4096))];
    B_shared[((((int)threadIdx.x) + 384))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            6144))];
    B_shared[((((int)threadIdx.x) + 512))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            8192))];
    B_shared[((((int)threadIdx.x) + 640))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            10240))];
    B_shared[((((int)threadIdx.x) + 768))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            12288))];
    B_shared[((((int)threadIdx.x) + 896))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            14336))];
    B_shared[((((int)threadIdx.x) + 1024))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))];
    B_shared[((((int)threadIdx.x) + 1152))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            18432))];
    B_shared[((((int)threadIdx.x) + 1280))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            20480))];
    B_shared[((((int)threadIdx.x) + 1408))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            22528))];
    B_shared[((((int)threadIdx.x) + 1536))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            24576))];
    B_shared[((((int)threadIdx.x) + 1664))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            26624))];
    B_shared[((((int)threadIdx.x) + 1792))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            28672))];
    B_shared[((((int)threadIdx.x) + 1920))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            30720))];
    B_shared[((((int)threadIdx.x) + 2048))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            32768))];
    B_shared[((((int)threadIdx.x) + 2176))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            34816))];
    B_shared[((((int)threadIdx.x) + 2304))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            36864))];
    B_shared[((((int)threadIdx.x) + 2432))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            38912))];
    B_shared[((((int)threadIdx.x) + 2560))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            40960))];
    B_shared[((((int)threadIdx.x) + 2688))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            43008))];
    B_shared[((((int)threadIdx.x) + 2816))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            45056))];
    B_shared[((((int)threadIdx.x) + 2944))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            47104))];
    B_shared[((((int)threadIdx.x) + 3072))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            49152))];
    B_shared[((((int)threadIdx.x) + 3200))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            51200))];
    B_shared[((((int)threadIdx.x) + 3328))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            53248))];
    B_shared[((((int)threadIdx.x) + 3456))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            55296))];
    B_shared[((((int)threadIdx.x) + 3584))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            57344))];
    B_shared[((((int)threadIdx.x) + 3712))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            59392))];
    B_shared[((((int)threadIdx.x) + 3840))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            61440))];
    B_shared[((((int)threadIdx.x) + 3968))] =
        B[((((((k_outer * 65536) + ((((int)threadIdx.x) >> 5) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 31)) +
            63488))];
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
  compute[((
      ((((((int)blockIdx.x) >> 4) * 4096) + ((((int)threadIdx.x) >> 4) * 512)) +
       ((((int)blockIdx.x) & 15) * 32)) +
      (((int)threadIdx.x) & 15)))] = compute_local[(0)];
  compute[(((((((((int)blockIdx.x) >> 4) * 4096) +
               ((((int)threadIdx.x) >> 4) * 512)) +
              ((((int)blockIdx.x) & 15) * 32)) +
             (((int)threadIdx.x) & 15)) +
            16))] = compute_local[(1)];
}
