#include <isl/map.h>
#include <isl/printer.h>
#include <isl/set.h>

#include <iostream>

char* str_context = "[N] -> { : N > 0}";
char* str_domain1 = "[N] -> {[i, j] : 0 <= i < N and 0 <= j < N}";
char* str_domain2 = "[N] -> {[i, j] : 0 <= i < N and 0 <= j < N}";

char* str_scattering1 = "[N] -> {[i, j] -> [0, i + j, j]}";
char* str_scattering2 = "[N] -> {[i, j] -> [1, i, -j]}";

void printSet(isl_set* set) {
  isl_printer* printer = isl_printer_to_file(isl_set_get_ctx(set), stdout);
  printer = isl_printer_set_output_format(printer, ISL_FORMAT_ISL);
  isl_printer_print_set(printer, set);
  std::cout << std::endl << std::endl;
  isl_printer_free(printer);
}

void printMap(isl_map* map) {
  isl_printer* printer = isl_printer_to_file(isl_map_get_ctx(map), stdout);
  printer = isl_printer_set_output_format(printer, ISL_FORMAT_ISL);
  isl_printer_print_map(printer, map);
  std::cout << std::endl << std::endl;
  isl_printer_free(printer);
}

int main() {
  isl_ctx* ctx;
  isl_set *set_context, *set1, *set2;
  isl_map *map1, *map2;

  ctx = isl_ctx_alloc();
  std::cout << "context set" << std::endl;
  set_context = isl_set_read_from_str(ctx, str_context);
  printSet(set_context);

  std::cout << "set 1:" << std::endl;
  set1 = isl_set_read_from_str(ctx, str_domain1);
  printSet(set1);

  std::cout << "set 2:" << std::endl;
  set2 = isl_set_read_from_str(ctx, str_domain2);
  printSet(set2);

  std::cout << "map 1:" << std::endl;
  map1 = isl_map_read_from_str(ctx, str_scattering1);
  printMap(map1);

  std::cout << "map 2:" << std::endl;
  map2 = isl_map_read_from_str(ctx, str_scattering2);
  printMap(map2);

  isl_ctx_free(ctx);
}
