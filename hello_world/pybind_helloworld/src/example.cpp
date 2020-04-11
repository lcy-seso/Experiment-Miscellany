#include <pybind11/pybind11.h>

#include <string>

namespace py = pybind11;

class Test {
 public:
  std::string info;
  Test(const std::string& info) : info(info) {}
  void setInfo(const std::string& info_) { info = info_; }
  const std::string& getInfo() const { return info; }
};

PYBIND11_MODULE(pybind_test, m) {
  py::class_<Test>(m, "Test")
      .def(py::init<const std::string&>())
      .def("setInfo", &Test::setInfo)
      .def("getInfo", &Test::getInfo);
}
