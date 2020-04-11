# Preparation

1. install python dependences.

  ```
  pip3 install pytest setuptools wheel
  ```

1. build the outer directory which automatically downloads pybind from github.

    ```bash
    cd ../
    mkdir build
    cd build
    cmake ../
    make
    ```
# Build

```bash
python3 setup.py build
```

or build the wheel.

```base
python3 setup.py bdist_wheel
```

# Test the binding

Suppose you do not build the wheel, but only the dynamic-link library:

```bash
cd build/lib.linux-x86_64-3.6
ln -s pybind_test.cpython-36m-x86_64-linux-gnu.so pybind_test.so

```

Test in Python REPL:
```
python3
Python 3.6.9 (default, Oct 18 2019, 12:36:05)
[GCC 5.5.0 20171010] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import pybind_test
>>> m = pybind_test.Test("hello world")
>>> m.getInfo()
'hello world'
```
