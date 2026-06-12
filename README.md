# LLM Command Parser Demo

Small proof-of-concept demo using a LLM for player input processing via [llama.cpp](https://github.com/ggml-org/llama.cpp) for a text-based game.

This project is made for fun and is not intended as a showcase of good or efficient practices.

## Layout

```
CMakeLists.txt        Top-level build
libs/llama.cpp/       llama.cpp (git submodule)
models/               GGUF weights go here
src/main.cpp          Entry point (hello world)
```

## Prerequisites

```bash
sudo apt-get update
sudo apt-get install -y build-essential cmake git curl pkg-config gdb
```

## Build

```bash
# 1. Fetch the llama.cpp submodule (first checkout only)
git submodule update --init --recursive

# 2. Configure + build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j

# 3. Run
./build/bin/LLMCommandParserDemo
```

## Switching to a GPU backend

The build is CPU-only by default. To use a GPU, install the matching SDK and
flip the flag in `CMakeLists.txt` (or pass it at configure time), e.g.:

```bash
cmake -S . -B build -DGGML_CUDA=ON      # NVIDIA / CUDA
cmake -S . -B build -DGGML_VULKAN=ON    # Vulkan
```
