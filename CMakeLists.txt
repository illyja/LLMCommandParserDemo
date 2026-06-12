cmake_minimum_required(VERSION 3.20)
project(LLMCommandParserDemo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default to an optimized build
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        Debug Release RelWithDebInfo MinSizeRel)
endif()

# ----------------------------------------------------------------------------
# llama.cpp (vendored as a git submodule under libs/llama.cpp)
# ----------------------------------------------------------------------------
# Trim everything we don't need so the submodule builds fast: just the core
# `llama` library plus the `common` helper library used by main.cpp.
set(LLAMA_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(LLAMA_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(LLAMA_BUILD_SERVER   OFF CACHE BOOL "" FORCE)
set(LLAMA_BUILD_TOOLS    OFF CACHE BOOL "" FORCE)
set(LLAMA_BUILD_COMMON   ON  CACHE BOOL "" FORCE)
set(LLAMA_CURL           OFF CACHE BOOL "" FORCE)  # no libcurl dependency

# CPU-only backend. Flip a flag ON (and install the matching SDK) for GPU later.
set(GGML_CUDA   OFF CACHE BOOL "" FORCE)
set(GGML_VULKAN OFF CACHE BOOL "" FORCE)
# Tune generated code to this machine's CPU.
# Set OFF if you intend to distribute.
set(GGML_NATIVE ON  CACHE BOOL "" FORCE)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/llama.cpp/CMakeLists.txt")
    message(FATAL_ERROR
        "libs/llama.cpp is missing/empty.\n"
        "Initialize the submodule first:\n"
        "    git submodule update --init --recursive")
endif()

add_subdirectory(libs/llama.cpp)

# ----------------------------------------------------------------------------
# Demo executable
# ----------------------------------------------------------------------------
add_executable(LLMCommandParserDemo
    src/main.cpp)

target_include_directories(LLMCommandParserDemo PRIVATE src)

# `llama-common` transitively brings in `llama` and `ggml` plus their includes.
target_link_libraries(LLMCommandParserDemo PRIVATE llama-common llama ggml)

set_target_properties(LLMCommandParserDemo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
