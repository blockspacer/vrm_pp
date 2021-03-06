# vrm_pp

> **Lightweight C++ preprocessor library.**

[![build][badge.build]][build]
[![stability][badge.stability]][stability]
[![license][badge.license]][license]
[![gratipay][badge.gratipay]][gratipay]
![badge.cpp](https://img.shields.io/badge/c++-98-ff69b4.svg?style=flat-square)
[![on-wandbox][badge.on-wandbox]][on-wandbox]
[![on-godbolt][badge.on-godbolt]][on-godbolt]

[badge.build]: https://img.shields.io/travis/SuperV1234/vrm_pp.svg?style=flat-square
[badge.stability]: https://img.shields.io/badge/stability-stable-green.svg?style=flat-square
[badge.license]: http://img.shields.io/badge/license-afl%203.0-blue.svg?style=flat-square
[badge.gratipay]: https://img.shields.io/gratipay/user/SuperV1234.svg?style=flat-square
[badge.on-wandbox]: https://img.shields.io/badge/on-wandbox-376666.svg?style=flat-square
[badge.on-godbolt]: https://img.shields.io/badge/on-godbolt-376666.svg?style=flat-square

[build]: https://travis-ci.org/SuperV1234/vrm_pp
[stability]: http://github.com/badges/stability-badges
[license]: https://github.com/SuperV1234/vrm_pp/blob/master/LICENSE
[gratipay]: https://gratipay.com/~SuperV1234/
[on-wandbox]: https://wandbox.org/permlink/3oM6SqIb0WLGy0iY
[on-godbolt]: https://godbolt.org/g/tJi4Sk



## Intended usage (quick start)

1. Add this repository and [SuperV1234/vrm_cmake](https://github.com/SuperV1234/vrm_cmake) as submodules of your project, as subfolders in `your_project/extlibs/`:

    ```bash
    git submodule add   https://github.com/SuperV1234/vrm_cmake.git   your_project/extlibs/vrm_cmake
    git submodule add   https://github.com/SuperV1234/vrm_pp.git      your_project/extlibs/vrm_pp
    ```

2. Include `vrm_cmake` in your project's `CMakeLists.txt` and look for the `vrm_pp` extlib:

    ```cmake
    # Include `vrm_cmake`:
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extlibs/vrm_cmake/cmake/")
    include(vrm_cmake)

    # Find `vrm_pp`:
    vrm_cmake_find_extlib(vrm_pp)
    ```
