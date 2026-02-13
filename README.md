## AlgoForge - C++ Data Structures & Algorithms Playground

This repository is a personal playground for learning and experimenting with:

- classic algorithms (sorting, searching, graph algorithms, etc.)
- data structures (lists, trees, hash tables, etc.)
- C++ language features and syntax
- concurrency and multithreading
- small benchmarks and performance experiments

### Project layout

- `src/algorithms` – algorithms demos and experiments
- `src/datastructures` – data structure implementations and examples
- `src/concurrency` – multithreading, `std::thread`, `std::async`, etc.
- `src/playground` – general C++ syntax / concepts playground
- `src/utils` – common utilities (e.g. simple benchmark helper)
- `tests` – simple executables / tests (can be replaced later with a real test framework)

### Build (Windows, PowerShell)

You need CMake (>= 3.20) and a C++20 compiler (MSVC, clang, or gcc via MinGW) plus a generator like Ninja or Visual Studio.

From the project root (`e:/AlgoForge`):

```pwsh
cmake -S . -B build -G "Ninja"
cmake --build build
ctest --test-dir build
```

If you prefer Visual Studio as generator:

```pwsh
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug
ctest --test-dir build -C Debug
```

### Running the playgrounds

After building, from `build` folder run for example:

```pwsh
./algorithms
./datastructures
./concurrency
./playground
```

On Windows with Visual Studio generator, the executables are in `build/Debug` or `build/Release`.

### Next steps

- add more `.cpp` files per topic and hook them into the existing executables
- or create new executables in `src/CMakeLists.txt` for specific experiments
- integrate a unit test framework when you feel like it

Have fun exploring C++ and algorithms!
