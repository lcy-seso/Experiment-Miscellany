#pragma once

#include "../utils.h"

void createKernelInfoMap(KernelFuncMap& kernelMap) {
  // matrix size: m = 64 n = 64, k = 64
  dim3 grid_mm_64_64_64(32, 1, 1);
  dim3 block_mm_64_64_64(64, 1, 1);
  KernelFuncInfo info_mm_64_64_64(64, 64, 64, &mm_64_64_64, &grid_mm_64_64_64,
                                  &block_mm_64_64_64);
  kernelMap.insert({"mm_64_64_64", info_mm_64_64_64});

  // // matrix size: m = 512 n = 64, k = 64
  // dim3 grid_mm_512_64_64(128, 1, 1);
  // dim3 block_mm_512_64_64(128, 1, 1);
  // KernelFuncInfo info_mm_512_64_64(512, 64, 64, &mm_512_64_64,
  //                                  &grid_mm_512_64_64, &block_mm_512_64_64);
  // kernelMap.insert({"mm_512_64_64", info_mm_512_64_64});

  // // matrix size: m = 32 n = 256, k = 256
  // dim3 grid_mm_32_256_256(64, 1, 1);
  // dim3 block_mm_32_256_256(64, 1, 1);
  // KernelFuncInfo info_mm_32_256_256(32, 256, 256, &mm_32_256_256,
  //                                   &grid_mm_32_256_256,
  //                                   &block_mm_32_256_256);
  // kernelMap.insert({"mm_32_256_256", info_mm_32_256_256});

  // // matrix size: m = 32 n = 1024, k = 1024
  // dim3 grid_mm_32_1024_1024(128, 1, 1);
  // dim3 block_mm_32_1024_1024(128, 1, 1);
  // KernelFuncInfo info_mm_32_1024_1024(32, 1024, 1024, &mm_32_1024_1024,
  //                                     &grid_mm_32_1024_1024,
  //                                     &block_mm_32_1024_1024);
  // kernelMap.insert({"mm_32_1024_1024", info_mm_32_1024_1024});

  // // matrix size: m = 128 n = 512, k = 512
  // dim3 grid_mm_128_512_512(128, 1, 1);
  // dim3 block_mm_128_512_512(256, 1, 1);
  // KernelFuncInfo info_mm_128_512_512(128, 512, 512, &mm_128_512_512,
  //                                    &grid_mm_128_512_512,
  //                                    &block_mm_128_512_512);
  // kernelMap.insert({"mm_128_512_512", info_mm_128_512_512});

  // // matrix size: m = 256 n = 1024, k = 1024
  // dim3 grid_mm_256_1024_1024(128, 1, 1);
  // dim3 block_mm_256_1024_1024(256, 1, 1);
  // KernelFuncInfo info_mm_256_1024_1024(256, 1024, 1024, &mm_256_1024_1024,
  //                                      &grid_mm_256_1024_1024,
  //                                      &block_mm_256_1024_1024);
  // kernelMap.insert({"mm_256_1024_1024", info_mm_256_1024_1024});

  // // matrix size: m = 512 n = 256, k = 256
  // dim3 grid_mm_512_256_256(128, 1, 1);
  // dim3 block_mm_512_256_256(512, 1, 1);
  // KernelFuncInfo info_mm_512_256_256(512, 256, 256, &mm_512_256_256,
  //                                    &grid_mm_512_256_256,
  //                                    &block_mm_512_256_256);
  // kernelMap.insert({"mm_512_256_256", info_mm_512_256_256});

  // // matrix size: m = 128 n = 1024, k = 1024
  // dim3 grid_mm_128_1024_1024(128, 1, 1);
  // dim3 block_mm_128_1024_1024(512, 1, 1);
  // KernelFuncInfo info_mm_128_1024_1024(128, 1024, 1024, &mm_128_1024_1024,
  //                                      &grid_mm_128_1024_1024,
  //                                      &block_mm_128_1024_1024);
  // kernelMap.insert({"mm_128_1024_1024", info_mm_128_1024_1024});

  // // matrix size: m = 64 n = 256, k = 256
  // dim3 grid_mm_64_256_256(128, 1, 1);
  // dim3 block_mm_64_256_256(128, 1, 1);
  // KernelFuncInfo info_mm_64_256_256(64, 256, 256, &mm_64_256_256,
  //                                   &grid_mm_64_256_256,
  //                                   &block_mm_64_256_256);
  // kernelMap.insert({"mm_64_256_256", info_mm_64_256_256});

  // // matrix size: m = 256 n = 512, k = 512
  // dim3 grid_mm_256_512_512(128, 1, 1);
  // dim3 block_mm_256_512_512(512, 1, 1);
  // KernelFuncInfo info_mm_256_512_512(256, 512, 512, &mm_256_512_512,
  //                                    &grid_mm_256_512_512,
  //                                    &block_mm_256_512_512);
  // kernelMap.insert({"mm_256_512_512", info_mm_256_512_512});

  // // matrix size: m = 256 n = 256, k = 256
  // dim3 grid_mm_256_256_256(128, 1, 1);
  // dim3 block_mm_256_256_256(256, 1, 1);
  // KernelFuncInfo info_mm_256_256_256(256, 256, 256, &mm_256_256_256,
  //                                    &grid_mm_256_256_256,
  //                                    &block_mm_256_256_256);
  // kernelMap.insert({"mm_256_256_256", info_mm_256_256_256});

  // // matrix size: m = 512 n = 128, k = 128
  // dim3 grid_mm_512_128_128(256, 1, 1);
  // dim3 block_mm_512_128_128(256, 1, 1);
  // KernelFuncInfo info_mm_512_128_128(512, 128, 128, &mm_512_128_128,
  //                                    &grid_mm_512_128_128,
  //                                    &block_mm_512_128_128);
  // kernelMap.insert({"mm_512_128_128", info_mm_512_128_128});

  // // matrix size: m = 64 n = 512, k = 512
  // dim3 grid_mm_64_512_512(128, 1, 1);
  // dim3 block_mm_64_512_512(256, 1, 1);
  // KernelFuncInfo info_mm_64_512_512(64, 512, 512, &mm_64_512_512,
  //                                   &grid_mm_64_512_512,
  //                                   &block_mm_64_512_512);
  // kernelMap.insert({"mm_64_512_512", info_mm_64_512_512});

  // // matrix size: m = 128 n = 256, k = 256
  // dim3 grid_mm_128_256_256(128, 1, 1);
  // dim3 block_mm_128_256_256(256, 1, 1);
  // KernelFuncInfo info_mm_128_256_256(128, 256, 256, &mm_128_256_256,
  //                                    &grid_mm_128_256_256,
  //                                    &block_mm_128_256_256);
  // kernelMap.insert({"mm_128_256_256", info_mm_128_256_256});

  // // matrix size: m = 64 n = 1024, k = 1024
  // dim3 grid_mm_64_1024_1024(128, 1, 1);
  // dim3 block_mm_64_1024_1024(128, 1, 1);
  // KernelFuncInfo info_mm_64_1024_1024(64, 1024, 1024, &mm_64_1024_1024,
  //                                     &grid_mm_64_1024_1024,
  //                                     &block_mm_64_1024_1024);
  // kernelMap.insert({"mm_64_1024_1024", info_mm_64_1024_1024});

  // // matrix size: m = 32 n = 64, k = 64
  // dim3 grid_mm_32_64_64(16, 1, 1);
  // dim3 block_mm_32_64_64(64, 1, 1);
  // KernelFuncInfo info_mm_32_64_64(32, 64, 64, &mm_32_64_64,
  // &grid_mm_32_64_64,
  //                                 &block_mm_32_64_64);
  // kernelMap.insert({"mm_32_64_64", info_mm_32_64_64});

  // // matrix size: m = 256 n = 64, k = 64
  // dim3 grid_mm_256_64_64(176, 1, 1);
  // dim3 block_mm_256_64_64(96, 1, 1);
  // KernelFuncInfo info_mm_256_64_64(256, 64, 64, &mm_256_64_64,
  //                                  &grid_mm_256_64_64, &block_mm_256_64_64);
  // kernelMap.insert({"mm_256_64_64", info_mm_256_64_64});

  // // matrix size: m = 256 n = 128, k = 128
  // dim3 grid_mm_256_128_128(128, 1, 1);
  // dim3 block_mm_256_128_128(256, 1, 1);
  // KernelFuncInfo info_mm_256_128_128(256, 128, 128, &mm_256_128_128,
  //                                    &grid_mm_256_128_128,
  //                                    &block_mm_256_128_128);
  // kernelMap.insert({"mm_256_128_128", info_mm_256_128_128});

  // // matrix size: m = 32 n = 512, k = 512
  // dim3 grid_mm_32_512_512(64, 1, 1);
  // dim3 block_mm_32_512_512(128, 1, 1);
  // KernelFuncInfo info_mm_32_512_512(32, 512, 512, &mm_32_512_512,
  //                                   &grid_mm_32_512_512,
  //                                   &block_mm_32_512_512);
  // kernelMap.insert({"mm_32_512_512", info_mm_32_512_512});

  // // matrix size: m = 512 n = 1024, k = 1024
  // dim3 grid_mm_512_1024_1024(128, 1, 1);
  // dim3 block_mm_512_1024_1024(512, 1, 1);
  // KernelFuncInfo info_mm_512_1024_1024(512, 1024, 1024, &mm_512_1024_1024,
  //                                      &grid_mm_512_1024_1024,
  //                                      &block_mm_512_1024_1024);
  // kernelMap.insert({"mm_512_1024_1024", info_mm_512_1024_1024});

  // // matrix size: m = 32 n = 128, k = 128
  // dim3 grid_mm_32_128_128(32, 1, 1);
  // dim3 block_mm_32_128_128(64, 1, 1);
  // KernelFuncInfo info_mm_32_128_128(32, 128, 128, &mm_32_128_128,
  //                                   &grid_mm_32_128_128,
  //                                   &block_mm_32_128_128);
  // kernelMap.insert({"mm_32_128_128", info_mm_32_128_128});

  // // matrix size: m = 128 n = 64, k = 64
  // dim3 grid_mm_128_64_64(88, 1, 1);
  // dim3 block_mm_128_64_64(96, 1, 1);
  // KernelFuncInfo info_mm_128_64_64(128, 64, 64, &mm_128_64_64,
  //                                  &grid_mm_128_64_64, &block_mm_128_64_64);
  // kernelMap.insert({"mm_128_64_64", info_mm_128_64_64});

  // // matrix size: m = 64 n = 128, k = 128
  // dim3 grid_mm_64_128_128(176, 1, 1);
  // dim3 block_mm_64_128_128(48, 1, 1);
  // KernelFuncInfo info_mm_64_128_128(64, 128, 128, &mm_64_128_128,
  //                                   &grid_mm_64_128_128,
  //                                   &block_mm_64_128_128);
  // kernelMap.insert({"mm_64_128_128", info_mm_64_128_128});

  // // matrix size: m = 128 n = 128, k = 128
  // dim3 grid_mm_128_128_128(256, 1, 1);
  // dim3 block_mm_128_128_128(64, 1, 1);
  // KernelFuncInfo info_mm_128_128_128(128, 128, 128, &mm_128_128_128,
  //                                    &grid_mm_128_128_128,
  //                                    &block_mm_128_128_128);
  // kernelMap.insert({"mm_128_128_128", info_mm_128_128_128});

  // // matrix size: m = 512 n = 512, k = 512
  // dim3 grid_mm_512_512_512(128, 1, 1);
  // dim3 block_mm_512_512_512(256, 1, 1);
  // KernelFuncInfo info_mm_512_512_512(512, 512, 512, &mm_512_512_512,
  //                                    &grid_mm_512_512_512,
  //                                    &block_mm_512_512_512);
  // kernelMap.insert({"mm_512_512_512", info_mm_512_512_512});
}
