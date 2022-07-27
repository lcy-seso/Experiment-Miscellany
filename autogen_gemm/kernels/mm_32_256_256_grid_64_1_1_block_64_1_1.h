
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
    mm_32_256_256(float* __restrict__ A, float* __restrict__ B,
                  float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[512];
  __shared__ float B_shared[4096];
  float A_shared_local[1];
  float B_shared_local[2];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  for (int k_outer = 0; k_outer < 2; ++k_outer) {
    __syncthreads();
    A_shared[(((int)threadIdx.x))] =
        A[(((((((int)blockIdx.x) >> 3) * 1024) + (k_outer * 128)) +
            ((int)threadIdx.x)))];
    A_shared[((((int)threadIdx.x) + 64))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            64))];
    A_shared[((((int)threadIdx.x) + 128))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            256))];
    A_shared[((((int)threadIdx.x) + 192))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) +
              (((((int)threadIdx.x) + 192) >> 7) * 256)) +
             (k_outer * 128)) +
            (((int)threadIdx.x) + 64)))];
    A_shared[((((int)threadIdx.x) + 256))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            512))];
    A_shared[((((int)threadIdx.x) + 320))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) +
              (((((int)threadIdx.x) + 320) >> 7) * 256)) +
             (k_outer * 128)) +
            (((int)threadIdx.x) + 64)))];
    A_shared[((((int)threadIdx.x) + 384))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) + (k_outer * 128)) +
             ((int)threadIdx.x)) +
            768))];
    A_shared[((((int)threadIdx.x) + 448))] =
        A[((((((((int)blockIdx.x) >> 3) * 1024) +
              (((((int)threadIdx.x) + 448) >> 7) * 256)) +
             (k_outer * 128)) +
            (((int)threadIdx.x) + 64)))];
    B_shared[(((int)threadIdx.x))] =
        B[(((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
             ((((int)blockIdx.x) & 7) * 32)) +
            (((int)threadIdx.x) & 31)))];
    B_shared[((((int)threadIdx.x) + 64))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            512))];
    B_shared[((((int)threadIdx.x) + 128))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            1024))];
    B_shared[((((int)threadIdx.x) + 192))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            1536))];
    B_shared[((((int)threadIdx.x) + 256))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            2048))];
    B_shared[((((int)threadIdx.x) + 320))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            2560))];
    B_shared[((((int)threadIdx.x) + 384))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            3072))];
    B_shared[((((int)threadIdx.x) + 448))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            3584))];
    B_shared[((((int)threadIdx.x) + 512))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            4096))];
    B_shared[((((int)threadIdx.x) + 576))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            4608))];
    B_shared[((((int)threadIdx.x) + 640))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            5120))];
    B_shared[((((int)threadIdx.x) + 704))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            5632))];
    B_shared[((((int)threadIdx.x) + 768))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            6144))];
    B_shared[((((int)threadIdx.x) + 832))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            6656))];
    B_shared[((((int)threadIdx.x) + 896))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            7168))];
    B_shared[((((int)threadIdx.x) + 960))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            7680))];
    B_shared[((((int)threadIdx.x) + 1024))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            8192))];
    B_shared[((((int)threadIdx.x) + 1088))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            8704))];
    B_shared[((((int)threadIdx.x) + 1152))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            9216))];
    B_shared[((((int)threadIdx.x) + 1216))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            9728))];
    B_shared[((((int)threadIdx.x) + 1280))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            10240))];
    B_shared[((((int)threadIdx.x) + 1344))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            10752))];
    B_shared[((((int)threadIdx.x) + 1408))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            11264))];
    B_shared[((((int)threadIdx.x) + 1472))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            11776))];
    B_shared[((((int)threadIdx.x) + 1536))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            12288))];
    B_shared[((((int)threadIdx.x) + 1600))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            12800))];
    B_shared[((((int)threadIdx.x) + 1664))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            13312))];
    B_shared[((((int)threadIdx.x) + 1728))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            13824))];
    B_shared[((((int)threadIdx.x) + 1792))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            14336))];
    B_shared[((((int)threadIdx.x) + 1856))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            14848))];
    B_shared[((((int)threadIdx.x) + 1920))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            15360))];
    B_shared[((((int)threadIdx.x) + 1984))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            15872))];
    B_shared[((((int)threadIdx.x) + 2048))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16384))];
    B_shared[((((int)threadIdx.x) + 2112))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            16896))];
    B_shared[((((int)threadIdx.x) + 2176))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            17408))];
    B_shared[((((int)threadIdx.x) + 2240))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            17920))];
    B_shared[((((int)threadIdx.x) + 2304))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            18432))];
    B_shared[((((int)threadIdx.x) + 2368))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            18944))];
    B_shared[((((int)threadIdx.x) + 2432))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            19456))];
    B_shared[((((int)threadIdx.x) + 2496))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            19968))];
    B_shared[((((int)threadIdx.x) + 2560))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            20480))];
    B_shared[((((int)threadIdx.x) + 2624))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            20992))];
    B_shared[((((int)threadIdx.x) + 2688))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            21504))];
    B_shared[((((int)threadIdx.x) + 2752))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            22016))];
    B_shared[((((int)threadIdx.x) + 2816))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            22528))];
    B_shared[((((int)threadIdx.x) + 2880))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            23040))];
    B_shared[((((int)threadIdx.x) + 2944))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            23552))];
    B_shared[((((int)threadIdx.x) + 3008))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            24064))];
    B_shared[((((int)threadIdx.x) + 3072))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            24576))];
    B_shared[((((int)threadIdx.x) + 3136))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            25088))];
    B_shared[((((int)threadIdx.x) + 3200))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            25600))];
    B_shared[((((int)threadIdx.x) + 3264))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            26112))];
    B_shared[((((int)threadIdx.x) + 3328))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            26624))];
    B_shared[((((int)threadIdx.x) + 3392))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            27136))];
    B_shared[((((int)threadIdx.x) + 3456))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            27648))];
    B_shared[((((int)threadIdx.x) + 3520))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            28160))];
    B_shared[((((int)threadIdx.x) + 3584))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            28672))];
    B_shared[((((int)threadIdx.x) + 3648))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            29184))];
    B_shared[((((int)threadIdx.x) + 3712))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            29696))];
    B_shared[((((int)threadIdx.x) + 3776))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            30208))];
    B_shared[((((int)threadIdx.x) + 3840))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            30720))];
    B_shared[((((int)threadIdx.x) + 3904))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            31232))];
    B_shared[((((int)threadIdx.x) + 3968))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            31744))];
    B_shared[((((int)threadIdx.x) + 4032))] =
        B[((((((k_outer * 32768) + ((((int)threadIdx.x) >> 5) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 31)) +
            32256))];
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
      ((((((int)blockIdx.x) >> 3) * 1024) + ((((int)threadIdx.x) >> 4) * 256)) +
       ((((int)blockIdx.x) & 7) * 32)) +
      (((int)threadIdx.x) & 15)))] = compute_local[(0)];
  compute[(((((((((int)blockIdx.x) >> 3) * 1024) +
               ((((int)threadIdx.x) >> 4) * 256)) +
              ((((int)blockIdx.x) & 7) * 32)) +
             (((int)threadIdx.x) & 15)) +
            16))] = compute_local[(1)];
}
