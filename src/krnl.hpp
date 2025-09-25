// This is a C++ header file for a kernel function that performs some operations on arrays.

typedef int data_t;

extern "C" void krnl_top(
            data_t* a, 
            data_t* b,
            data_t* c,
            int size
        );
