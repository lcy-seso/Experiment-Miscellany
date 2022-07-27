
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
    mm_32_128_128(float* __restrict__ A, float* __restrict__ B,
                  float* __restrict__ compute) {
  float compute_local[2];
  __shared__ float A_shared[512];
  __shared__ float B_shared[4096];
  float A_shared_local[1];
  float B_shared_local[2];
  compute_local[(0)] = 0.000000e+00f;
  compute_local[(1)] = 0.000000e+00f;
  A_shared[(((int)threadIdx.x))] =
      A[((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)))];
  A_shared[((((int)threadIdx.x) + 64))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 64))];
  A_shared[((((int)threadIdx.x) + 128))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 128))];
  A_shared[((((int)threadIdx.x) + 192))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 192))];
  A_shared[((((int)threadIdx.x) + 256))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 256))];
  A_shared[((((int)threadIdx.x) + 320))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 320))];
  A_shared[((((int)threadIdx.x) + 384))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 384))];
  A_shared[((((int)threadIdx.x) + 448))] =
      A[(((((((int)blockIdx.x) >> 2) * 512) + ((int)threadIdx.x)) + 448))];
  B_shared[(((int)threadIdx.x))] =
      B[(((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
          (((int)threadIdx.x) & 31)))];
  B_shared[((((int)threadIdx.x) + 64))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       256))];
  B_shared[((((int)threadIdx.x) + 128))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       512))];
  B_shared[((((int)threadIdx.x) + 192))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       768))];
  B_shared[((((int)threadIdx.x) + 256))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       1024))];
  B_shared[((((int)threadIdx.x) + 320))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       1280))];
  B_shared[((((int)threadIdx.x) + 384))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       1536))];
  B_shared[((((int)threadIdx.x) + 448))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       1792))];
  B_shared[((((int)threadIdx.x) + 512))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       2048))];
  B_shared[((((int)threadIdx.x) + 576))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       2304))];
  B_shared[((((int)threadIdx.x) + 640))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       2560))];
  B_shared[((((int)threadIdx.x) + 704))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       2816))];
  B_shared[((((int)threadIdx.x) + 768))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       3072))];
  B_shared[((((int)threadIdx.x) + 832))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       3328))];
  B_shared[((((int)threadIdx.x) + 896))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       3584))];
  B_shared[((((int)threadIdx.x) + 960))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       3840))];
  B_shared[((((int)threadIdx.x) + 1024))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       4096))];
  B_shared[((((int)threadIdx.x) + 1088))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       4352))];
  B_shared[((((int)threadIdx.x) + 1152))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       4608))];
  B_shared[((((int)threadIdx.x) + 1216))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       4864))];
  B_shared[((((int)threadIdx.x) + 1280))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       5120))];
  B_shared[((((int)threadIdx.x) + 1344))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       5376))];
  B_shared[((((int)threadIdx.x) + 1408))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       5632))];
  B_shared[((((int)threadIdx.x) + 1472))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       5888))];
  B_shared[((((int)threadIdx.x) + 1536))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       6144))];
  B_shared[((((int)threadIdx.x) + 1600))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       6400))];
  B_shared[((((int)threadIdx.x) + 1664))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       6656))];
  B_shared[((((int)threadIdx.x) + 1728))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       6912))];
  B_shared[((((int)threadIdx.x) + 1792))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       7168))];
  B_shared[((((int)threadIdx.x) + 1856))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       7424))];
  B_shared[((((int)threadIdx.x) + 1920))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       7680))];
  B_shared[((((int)threadIdx.x) + 1984))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       7936))];
  B_shared[((((int)threadIdx.x) + 2048))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       8192))];
  B_shared[((((int)threadIdx.x) + 2112))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       8448))];
  B_shared[((((int)threadIdx.x) + 2176))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       8704))];
  B_shared[((((int)threadIdx.x) + 2240))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       8960))];
  B_shared[((((int)threadIdx.x) + 2304))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       9216))];
  B_shared[((((int)threadIdx.x) + 2368))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       9472))];
  B_shared[((((int)threadIdx.x) + 2432))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       9728))];
  B_shared[((((int)threadIdx.x) + 2496))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       9984))];
  B_shared[((((int)threadIdx.x) + 2560))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       10240))];
  B_shared[((((int)threadIdx.x) + 2624))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       10496))];
  B_shared[((((int)threadIdx.x) + 2688))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       10752))];
  B_shared[((((int)threadIdx.x) + 2752))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       11008))];
  B_shared[((((int)threadIdx.x) + 2816))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       11264))];
  B_shared[((((int)threadIdx.x) + 2880))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       11520))];
  B_shared[((((int)threadIdx.x) + 2944))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       11776))];
  B_shared[((((int)threadIdx.x) + 3008))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       12032))];
  B_shared[((((int)threadIdx.x) + 3072))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       12288))];
  B_shared[((((int)threadIdx.x) + 3136))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       12544))];
  B_shared[((((int)threadIdx.x) + 3200))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       12800))];
  B_shared[((((int)threadIdx.x) + 3264))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       13056))];
  B_shared[((((int)threadIdx.x) + 3328))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       13312))];
  B_shared[((((int)threadIdx.x) + 3392))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       13568))];
  B_shared[((((int)threadIdx.x) + 3456))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       13824))];
  B_shared[((((int)threadIdx.x) + 3520))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       14080))];
  B_shared[((((int)threadIdx.x) + 3584))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       14336))];
  B_shared[((((int)threadIdx.x) + 3648))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       14592))];
  B_shared[((((int)threadIdx.x) + 3712))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       14848))];
  B_shared[((((int)threadIdx.x) + 3776))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       15104))];
  B_shared[((((int)threadIdx.x) + 3840))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       15360))];
  B_shared[((((int)threadIdx.x) + 3904))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       15616))];
  B_shared[((((int)threadIdx.x) + 3968))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       15872))];
  B_shared[((((int)threadIdx.x) + 4032))] = B[(
      (((((((int)threadIdx.x) >> 5) * 128) + ((((int)blockIdx.x) & 3) * 32)) +
        (((int)threadIdx.x) & 31)) +
       16128))];
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
  compute[(
      (((((((int)blockIdx.x) >> 2) * 512) + ((((int)threadIdx.x) >> 4) * 128)) +
        ((((int)blockIdx.x) & 3) * 32)) +
       (((int)threadIdx.x) & 15)))] = compute_local[(0)];
  compute[((
      (((((((int)blockIdx.x) >> 2) * 512) + ((((int)threadIdx.x) >> 4) * 128)) +
        ((((int)blockIdx.x) & 3) * 32)) +
       (((int)threadIdx.x) & 15)) +
      16))] = compute_local[(1)];
}
