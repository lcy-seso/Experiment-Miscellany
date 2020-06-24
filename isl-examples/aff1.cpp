#include "isl_printer.h"
#include "util.h"

isl_aff* Aff1(isl_ctx* ctx) {
  isl_space* space = isl_space_set_alloc(ctx, 0, 2);

  // create set.
  isl_set* dom = isl_set_universe(space);
  dom = isl_set_set_tuple_name(dom, "A");
  dom = isl_set_lower_bound_si(dom, isl_dim_set, 0, 5);
  dom = isl_set_upper_bound_si(dom, isl_dim_set, 0, 23);
  dom = isl_set_set_dim_name(dom, isl_dim_set, 0, "i");

  dom = isl_set_set_dim_name(dom, isl_dim_set, 1, "j");
  dom = isl_set_lower_bound_si(dom, isl_dim_set, 1, 7);
  dom = isl_set_upper_bound_si(dom, isl_dim_set, 1, 11);

  isl_local_space* ls = isl_local_space_from_space(space);
  isl_aff* aff = isl_aff_zero_on_domain(ls);

  aff = isl_aff_add_coefficient_si(aff, isl_dim_in, 0, 2);
  aff = isl_aff_add_coefficient_si(aff, isl_dim_in, 1, 5);
  aff = isl_aff_scale_down_ui(aff, 3);

  aff = isl_aff_floor(aff);
  aff = isl_aff_add_constant_si(aff, -3);
  return aff;
}

void Aff2(isl_ctx* ctx) {
  // const char* str = "[M] -> {[C[x, N] -> B[]] -> [x + floor(N/2)]}";
  // isl_pw_multi_aff* pma = isl_pw_multi_aff_read_from_str(ctx, str);
  isl_aff* aff = Aff1(ctx);
  isl_multi_aff* ma = isl_multi_aff_from_aff(aff);

  std::cout << ma << std::endl;
}

// void Aff3() {
//   int i;
//   isl_size n;
//   isl_multi_pw_aff* mpa;
//
//   n = isl_multi_aff_dim(ma, isl_dim_out);
//   if (n < 0) ma = isl_multi_aff_free(ma);
//   if (!ma) return NULL;
//
//   mpa = isl_multi_pw_aff_alloc(isl_multi_aff_get_space(ma));
//
//   for (i = 0; i < n; ++i) {
//     isl_pw_aff* pa;
//
//     pa = isl_pw_aff_from_aff(isl_multi_aff_get_aff(ma, i));
//     mpa = isl_multi_pw_aff_set_pw_aff(mpa, i, pa);
//   }
//
//   isl_multi_aff_free(ma);
//   return mpa;
// }

int main() {
  struct isl_options* options = isl_options_new_with_defaults();
  isl_ctx* ctx = isl_ctx_alloc_with_options(&isl_options_args, options);

  Aff2(ctx);

  isl_ctx_free(ctx);
}
