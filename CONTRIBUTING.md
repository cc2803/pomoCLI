# Contributing

This file just records the expected workflow for consistency. Follow the guidelines below, contributions are welcome!

## Building

```bash
cmake -B build -S .
cmake --build build
```

Without CMake:

```bash
g++ -std=c++17 -Iinclude -o pomo src/main.cpp src/Timer.cpp src/Session.cpp
```

## Running tests

Once the Catch2 test suite lands (see `CHANGELOG.md` / the project roadmap), run:

```bash
ctest --test-dir build --output-on-failure
```

`Session::run()` is intentionally not unit-tested — it's pure orchestration (looping,
constructing `Timer`s, calling `celebrate()`) with no independent branching logic worth
isolating from the pieces it coordinates.

## Formatting

Run `clang-format -i` on any changed `.cpp`/`.h` files before committing. The style is
defined in `.clang-format`.

## Pull requests

Use the PR template; keep changes focused and describe what you tested.
