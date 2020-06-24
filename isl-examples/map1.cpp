#include "isl_printer.h"
#include "util.h"

void Map1(isl_ctx* ctx) {
  // parameter space
  isl_space* space =
      isl_space_alloc(ctx, 1 /*num parameter*/, 2 /*in dim*/, 1 /*out dim*/);

  isl_map* map = isl_map_universe(space);
  map = isl_map_set_tuple_name(map, isl_dim_in, "A");

  map = isl_map_set_dim_name(map, isl_dim_param, 0, "n");
  map = isl_map_lower_bound_si(map, isl_dim_param, 0, 5);

  map = isl_map_set_dim_name(map, isl_dim_in, 0, "i");
  map = isl_map_set_dim_name(map, isl_dim_in, 1, "j");
  map = isl_map_lower_bound_si(map, isl_dim_in, 0, 5);

  map = isl_map_set_tuple_name(map, isl_dim_out, "B");
  map = isl_map_set_dim_name(map, isl_dim_out, 0, "k");

  std::cout << map << std::endl;

  isl_space_free(space);
}

void Map2(isl_ctx* ctx) {
  isl_space* space = isl_space_params_alloc(ctx, 2);
  // std::cout << "parameter space: " << space << std::endl;

  // set space
  // a zero dimensional set can be created from parameter domain
  space = isl_space_set_from_params(space);
  space = isl_space_add_dims(space, isl_dim_set, 1);

  // map space
  space = isl_space_map_from_set(space);

  isl_constraint* c =
      isl_constraint_alloc_equality(isl_local_space_from_space(space));
  c = isl_constraint_set_coefficient_si(c, isl_dim_in, 0, 1);
  c = isl_constraint_set_coefficient_si(c, isl_dim_out, 0, -1);

  isl_basic_map* bmap1 = isl_basic_map_from_constraint(isl_constraint_copy(c));

  c = isl_constraint_set_constant_si(c, 1);

  isl_basic_map* bmap2 = isl_basic_map_from_constraint(c);

  bmap1 = isl_basic_map_upper_bound_si(bmap1, isl_dim_in, 0, 5);
  bmap2 = isl_basic_map_lower_bound_si(bmap2, isl_dim_in, 0, 5);

  isl_map* map = isl_basic_map_union(bmap1, bmap2);
  std::cout << map << std::endl;
}

int main() {
  struct isl_options* options = isl_options_new_with_defaults();
  isl_ctx* ctx = isl_ctx_alloc_with_options(&isl_options_args, options);

  isl_printer* p = isl_printer_to_file(ctx, stdout);
  p = isl_printer_set_output_format(p, ISL_FORMAT_ISL);

  Map1(ctx);
  Map2(ctx);

  isl_printer_free(p);
  isl_ctx_free(ctx);
}
