#include <cstdio>

#include "llama.h"

// Hello world
int main() {
    printf("LLM Command Parser Demo - build OK.\n");

    // Test call to the library
    printf("llama.cpp system info: %s\n", llama_print_system_info());

    return 0;
}
