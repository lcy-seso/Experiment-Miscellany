#include <isl/set.h>

int nb_parameters = 1;
char* parameter_name[] = {"N"};
char* iterator_name[] = {"i", "j"};
char* scattering_name[] = {"t0", "t1", "t2"};
char* str_context = "[N] -> { : N > 0}";
char* str_domain1 = "[N] -> {[i, j] : 0 <= i < N and 0 <= j < N}";
char* str_domain2 = "[N] -> {[i, j] : 0 <= i < N and 0 <= j < N}";
char* str_scattering1 = "[N] -> {[i, j] -> [0, i + j, j]}";
char* str_scattering2 = "[N] -> {[i, j] -> [1, i,    -j]}";

int main() {
  isl_ctx* ctx;
  isl_set *set_context, *set1, *set2;
  isl_map *map1, *map2;

  ctx = isl_ctx_alloc();
  set_context = isl_set_read_from_str(ctx, str_context);

  set1 = isl_set_read_from_str(ctx, str_domain1);
  set2 = isl_set_read_from_str(ctx, str_domain2);
  map1 = isl_map_read_from_str(ctx, str_scattering1);
  map2 = isl_map_read_from_str(ctx, str_scattering2);

  isl_ctx_free(ctx);
}
