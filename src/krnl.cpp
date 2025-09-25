#include "krnl.hpp"

void krnl(data_t* a, data_t* b, data_t* c, int size) {
    #pragma HLS INTERFACE m_axi port=a bundle=gmem1 depth=64
    #pragma HLS INTERFACE m_axi port=b bundle=gmem2 depth=64
    #pragma HLS INTERFACE m_axi port=c bundle=gmem3 depth=64
    #pragma HLS INTERFACE s_axilite port=size bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control

    for (int i = 0; i < size; i++){ 
        #pragma HLS PIPELINE
        c[i] = a[i] + b[i];
    }
}

extern "C" {
void krnl_top(data_t* a, data_t* b, data_t* c, int size) {

    #pragma HLS INTERFACE m_axi port=a bundle=gmem1 depth=64
    #pragma HLS INTERFACE m_axi port=b bundle=gmem2 depth=64
    #pragma HLS INTERFACE m_axi port=c bundle=gmem3 depth=64
    #pragma HLS INTERFACE s_axilite port=size bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    
    krnl(a, b, c, size);
}
}


