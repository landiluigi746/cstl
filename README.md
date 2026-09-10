<div align="center">
    <h1>cstl</h1>
    <h5>Reexploring C99 through C++ STL abstractions and library design 🚀</h5>
</div>

<p align="center">
    <img src="https://img.shields.io/badge/Language-C99-blue">
    <img src="https://img.shields.io/github/license/landiluigi746/cstl">
</p>

**cstl** is a lightweight header/source C99 library designed to explore low-level memory mechanics, generic container abstractions, and API design trade-offs by attempting to recreate key C++ Standard Template Library (STL) features in pure C.

> 💡 **Let's be honest:** You can't truly replicate the C++ STL in C. Without native templates, constructors/destructors, operator overloading, or compiler-enforced RAII, `cstl` isn't a drop-in replacement for `std::`. Instead, it is an educational exploration into library architecture, manual memory management, and generic design patterns within standard C99.

## ✨ Features / Implemented Modules

| Module             | Core Concept       | Description                                                                                       |
| ------------------ | ------------------ | ------------------------------------------------------------------------------------------------- |
| **`vector`**       | Dynamic Array      | Resizable generic container with amortized O(1) dynamic growth via `realloc`                      |
| **`string`**       | Dynamic String     | Self-managing character buffer with concatenation, length tracking, and explicit null-termination |
| **`memory`**       | Arena Allocator    | Region-based bump allocation for ultra-fast batch memory allocations and O(1) resets              |
| **`shared_ptr`**   | Reference Counting | Heap control block tracking strong references with custom cleanup callbacks                       |
| **`forward_list`** | Singly Linked List | O(1) head operations, explicit node traversal, and pointer manipulation                           |
| **`iterator`**     | Traversal Wrapper  | Basic cursor and generic pointer abstractions for iterating over structures                       |
| **`algorithm`**    | Generic Utilities  | Operations for searching, iteration through generic containers with function pointers             |

## 🔮 Roadmap

Planned modules and features coming soon:

- **`unordered_map`** (Hash table with chaining)
- **`list`** (Doubly linked list)
- New **`algorithm`** features (generic sorting mainly)

## 🚀 Quick Start

### Prerequisites

- Git
- CMake 3.16+
- C99-compatible compiler (`gcc`, `clang`, or `msvc`)

### Building from Source

```bash
# Clone the repository
git clone https://github.com/landiluigi746/cstl.git
cd cstl

# Configure and build
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel $(nproc)

# Run tests
ctest --test-dir build
```

### Using cstl in your CMake project

The suggested way to integrate cstl into your own CMake project is via FetchContent:

```cmake
include(FetchContent)

FetchContent_Declare(
    cstl
    GIT_REPOSITORY https://github.com/landiluigi746/cstl.git
    GIT_TAG master
    GIT_SHALLOW TRUE # perform shallow clone (only the latest commit)
)
FetchContent_MakeAvailable(cstl)
```

Then link the target to your executable:

```cmake
# in your CMakeLists.txt

add_executable(MyProject main.c)
target_link_libraries(MyProject PRIVATE cstl)
```

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👥 Contributing

Contributions are welcome! If you find any bugs or have any suggestions, please [open an issue](https://github.com/landiluigi746/cstl/issues/new) or [submit a pull request](https://github.com/landiluigi746/cstl/pulls).
Contributing guidelines will be added soon.

---

<p align="center">Drop a ⭐ if you like this project!</p>
