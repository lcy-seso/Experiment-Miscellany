import os

src_directory = 'kernels_gen'
trg_directory = 'kernels'

FUNC_DECL_FILE = 'kernel_func_def.h'
KERNEL_DECL_FILE = 'generated_kernels.h'


def post_process():
    with open(os.path.join(trg_directory, KERNEL_DECL_FILE),
              'w') as fheader, open(
                  os.path.join(trg_directory, FUNC_DECL_FILE), 'w') as fdef:
        fheader.write('#pragma once\n\n')
        fdef.write('#pragma once\n\n#include "../utils.h"\n\n')

        fdef.write('void createKernelInfoMap(KernelFuncMap& kernelMap) {\n')

        for filename in os.listdir(src_directory):
            path = os.path.join(src_directory, filename)
            if os.path.isfile(path):
                filename_split = filename.split('.')[0].split('_')

                m = int(filename_split[-3])
                n = int(filename_split[-2])
                k = int(filename_split[-1])

                print('m, n, k = [%d, %d, %d]' % (m, n, k))

                new_name_prefix = f'mm_{m}_{n}_{k}'

                with open(path, 'r') as fin:
                    contents = fin.read()
                    old_kernel_func_name = 'default_function_kernel0'

                    contents = contents.replace(old_kernel_func_name,
                                                new_name_prefix)

                    lines = contents.split('\n')
                    grid = lines[-3]
                    block = lines[-2]

                    contents = contents.replace(grid, '')
                    contents = contents.replace(block, '')

                    grid = grid.replace('dim3 grid(', '')
                    grid = grid.replace(');', '')
                    grid_x, grid_y, grid_z = grid.split(', ')
                    grid_str = (f'dim3 grid_{new_name_prefix}'
                                f'({grid_x}, {grid_y}, {grid_z});')

                    block = block.replace('dim3 block(', '')
                    block = block.replace(');', '')
                    block_x, block_y, block_z = block.split(', ')
                    block_str = (f'dim3 block_{new_name_prefix}'
                                 f'({block_x}, {block_y}, {block_z});')

                    fdef.write(f'// matrix size: m = {m} n = {n}, k = {k}\n')

                    kernel_info_str = (
                        f'{grid_str}\n{block_str}\n'
                        f'KernelFuncInfo info_{new_name_prefix}('
                        f'{m}, {n}, {k}, &{new_name_prefix}, '
                        f'&grid_{new_name_prefix}, '
                        f'&block_{new_name_prefix});\n')
                    fdef.write('%s' % (kernel_info_str))

                    fdef.write('kernelMap.insert({')
                    fdef.write(f'"{new_name_prefix}", info_{new_name_prefix}')
                    fdef.write('});\n\n')

                    new_file = (f'{new_name_prefix}_'
                                f'grid_{grid_x}_{grid_y}_{grid_z}_'
                                f'block_{block_x}_{block_y}_{block_z}.h')

                    fheader.write('%s\n' % (f'#include "{new_file}"'))
                    with open(os.path.join(trg_directory, new_file),
                              'w') as fout:
                        fout.write(contents)
        fdef.write('}\n')


if __name__ == '__main__':
    post_process()
