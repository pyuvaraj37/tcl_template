#include "krnl.hpp"
#include <iostream>
#include "hls_stream.h"

int main() {
    int DATA_SIZE = 64;
    
    data_t a[DATA_SIZE];
    data_t b[DATA_SIZE];
    data_t c[DATA_SIZE];

    // Initialize input arrays
    for (int i = 0; i < DATA_SIZE; i++) {
        a[i] = i * 2; // Static values: even numbers
        b[i] = i * 3; // Static values: multiples of 3
    }
    // Call the kernel function
    krnl_top(a, b, c, DATA_SIZE);

    // Verify the output
    for (int i = 0; i < DATA_SIZE; i++) {
        if (c[i] != a[i] + b[i]) {
            std::cout << "Error at index " << i << ": expected " << a[i] + b[i] << ", got " << c[i] << std::endl;
            return 1;
        } else {
            std::cout << "Test passed for index " << i << ": " << c[i] << std::endl;
        }
    }
    std::cout << "All tests passed!" << std::endl;
    return 0;
}