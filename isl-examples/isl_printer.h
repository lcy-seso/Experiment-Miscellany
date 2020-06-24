#include "util.h"

#define PRINTER_FUNC(isl_type)                                          \
  static inline std::ostream& operator<<(std::ostream& out,             \
                                         isl_##isl_type* val) {         \
    isl_printer* p = isl_printer_to_str(isl_##isl_type##_get_ctx(val)); \
    p = isl_printer_print_##isl_type(p, val);                           \
    char* str = isl_printer_get_str(p);                                 \
    isl_printer_free(p);                                                \
    out << std::string(str);                                            \
    free(str);                                                          \
    return out;                                                         \
  }
PRINTER_FUNC(map)
PRINTER_FUNC(basic_map)
PRINTER_FUNC(basic_set)
PRINTER_FUNC(point)
PRINTER_FUNC(aff)
PRINTER_FUNC(multi_pw_aff)
PRINTER_FUNC(pw_aff)
PRINTER_FUNC(id)
PRINTER_FUNC(schedule)
PRINTER_FUNC(constraint)
PRINTER_FUNC(set)
PRINTER_FUNC(union_set)
PRINTER_FUNC(space)
PRINTER_FUNC(multi_aff)
PRINTER_FUNC(pw_multi_aff)
