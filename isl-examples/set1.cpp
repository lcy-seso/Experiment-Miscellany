#include "isl_printer.h"
#include "util.h"

static isl_stat print_point(__isl_take isl_point* pnt, void* user) {
  std::cout << pnt << std::endl;
  return isl_stat_ok;
}

void Set1(isl_ctx* ctx) {  // A set.

  // Whenever a new set, relation or similar object is created from scratch, the
  // space in which it lives needs to be speciﬁed using an isl_space.

  // Each space involves:
  // 1. zero or more parameters; AND 2. zero, one or two tuples of set;
  // 3. OR input/output dimensions.

  // The parameters and dimensions are identiﬁed by an isl_dim_type and a
  // position.

  // The type isl_dim_param refers to parameters,
  // The type isl_dim_set refers to set dimensions for spaces with a single
  // tuple of dimensions.
  // The types isl_dim_in and isl_dim_out refer to input and output dimensions.

  isl_space* space =
      isl_space_set_alloc(ctx, 0 /*num parameters*/, 2 /* dim */);
  isl_set* dom = isl_set_universe(space);
  dom = isl_set_set_tuple_name(dom, "A");
  dom = isl_set_lower_bound_si(dom, isl_dim_set, 0, 5);
  dom = isl_set_upper_bound_si(dom, isl_dim_set, 0, 7);
  dom = isl_set_set_dim_name(dom, isl_dim_set, 0, "i");

  dom = isl_set_set_dim_name(dom, isl_dim_set, 1, "j");
  dom = isl_set_lower_bound_si(dom, isl_dim_set, 1, 7);
  dom = isl_set_upper_bound_si(dom, isl_dim_set, 1, 11);

  // print points in the set.
  isl_set_foreach_point(dom, &print_point, nullptr);

  std::cout << dom;

  isl_space_free(space);
}

void Set2(isl_ctx* ctx) {
  // parameter space
  isl_space* space = isl_space_params_alloc(ctx, 2);

  isl_id* id = isl_id_alloc(ctx, "i", nullptr);
  space = isl_space_set_dim_id(space, isl_dim_param, 0, id);

  id = isl_id_alloc(ctx, "j", nullptr);
  space = isl_space_set_dim_id(space, isl_dim_param, 1, id);

  isl_set* dom = isl_set_universe(space);
  dom = isl_set_lower_bound_si(dom, isl_dim_param, 0, 0);
  dom = isl_set_upper_bound_si(dom, isl_dim_param, 0, 5);

  dom = isl_set_lower_bound_si(dom, isl_dim_param, 1, 1);
  dom = isl_set_upper_bound_si(dom, isl_dim_param, 1, 3);

  // print points in the set.
  isl_set_foreach_point(dom, &print_point, nullptr);

  std::cout << dom << std::endl;

  isl_set_free(dom);
  isl_space_free(space);
}

void Set3(isl_ctx* ctx) {
  isl_space* space = isl_space_unit(ctx);  // create parameter space.
  space = isl_space_add_unnamed_tuple_ui(
      space, 1 /*dim*/);  // set from paramter domain.

  isl_multi_aff* ma =
      isl_multi_aff_identity_on_domain_space(isl_space_copy(space));
  isl_aff* var = isl_multi_aff_get_at(ma, 0);  // [i0] -> [(i0)]

  isl_val* v = isl_val_int_from_ui(ctx, 10);
  isl_aff* cst =
      isl_aff_val_on_domain_space(isl_space_copy(space), v);  // {[i0] ->[(10)]}

  isl_basic_set* bset = isl_aff_ge_basic_set(isl_aff_copy(var), cst);
  std::cout << bset << std::endl;

  v = isl_val_int_from_si(ctx, 42);
  cst = isl_aff_val_on_domain_space(space, v);
  bset = isl_basic_set_intersect(bset, isl_aff_le_basic_set(var, cst));

  std::cout << bset << std::endl;

  isl_val* two = isl_val_int_from_si(ctx, 2);
  ma = isl_multi_aff_scale_val(ma, isl_val_copy(two));
  bset = isl_basic_set_preimage_multi_aff(bset, isl_multi_aff_copy(ma));
  std::cout << bset << std::endl;

  ma = isl_multi_aff_scale_down_val(ma, isl_val_copy(two));
  ma = isl_multi_aff_scale_down_val(ma, two);
  bset = isl_basic_set_preimage_multi_aff(bset, ma);

  std::cout << bset << std::endl;
}

void Set4(isl_ctx* ctx) {
  isl_space* space = isl_space_set_alloc(ctx, 1 /*num param*/, 2 /*dim*/);
  isl_val* val = isl_val_int_from_si(ctx, 10);

  isl_set* set1 = isl_set_universe(space);

  set1 = isl_set_set_tuple_name(set1, "A");
  set1 = isl_set_lower_bound_val(set1, isl_dim_param, 0, val);
  set1 = isl_set_upper_bound_si(set1, isl_dim_param, 0, 25);
  set1 = isl_set_set_dim_name(set1, isl_dim_param, 0, "N");

  set1 = isl_set_lower_bound_si(set1, isl_dim_set, 0, 5);
  set1 = isl_set_upper_bound_si(set1, isl_dim_set, 0, 7);
  set1 = isl_set_set_dim_name(set1, isl_dim_set, 0, "i");

  set1 = isl_set_set_dim_name(set1, isl_dim_set, 1, "j");
  set1 = isl_set_lower_bound_si(set1, isl_dim_set, 1, 7);
  set1 = isl_set_upper_bound_si(set1, isl_dim_set, 1, 11);

  std::cout << "set 1: " << set1 << std::endl;

  // isl_set* set2 = isl_set_universe(isl_space_copy(space));

  // set2 = isl_set_lower_bound_si(set2, isl_dim_set, 0, 4);
  // set2 = isl_set_upper_bound_si(set2, isl_dim_set, 0, 9);

  // set2 = isl_set_lower_bound_si(set2, isl_dim_set, 1, 5);
  // set2 = isl_set_upper_bound_si(set2, isl_dim_set, 1, 7);

  // std::cout << "set 2: " << set2 << std::endl;

  // isl_set* set3 = isl_set_intersect_params(set1, set2);

  // // isl_set* set3 = isl_set_intersect(set1, set2);
  // std::cout << "set 3: " << set3 << std::endl;
}

void Set5(isl_ctx* ctx) {
  // const char* str = "[n] -> { A[i] : 0 <= i < n; B[]  }";
  // isl_union_set* uset = isl_union_set_read_from_str(ctx, str);

  const char* str = "[N, M] -> { A[i, j] : i < N, j < M}";
  isl_set* set = isl_set_read_from_str(ctx, str);
  set = isl_set_lower_bound_si(set, isl_dim_param, 0, 5);
  set = isl_set_upper_bound_si(set, isl_dim_param, 0, 25);

  set = isl_set_lower_bound_si(set, isl_dim_param, 1, 15);
  set = isl_set_upper_bound_si(set, isl_dim_param, 1, 50);

  std::cout << set << std::endl;
}

int main() {
  struct isl_options* options = isl_options_new_with_defaults();
  isl_ctx* ctx = isl_ctx_alloc_with_options(&isl_options_args, options);

  isl_printer* p = isl_printer_to_file(ctx, stdout);
  p = isl_printer_set_output_format(p, ISL_FORMAT_ISL);

  // Set1(ctx);
  // Set2(ctx);
  // Set3(ctx);
  // Set4(ctx);

  Set5(ctx);

  isl_printer_free(p);
  isl_ctx_free(ctx);
}
