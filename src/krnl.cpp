#include "krnl.hpp"

// void krnl(int* a, int* b, int* c, int size) {
//     for (int i = 0; i < size; i++){ 
//         #pragma HLS PIPELINE OFF
//         c[i] = a[i] + b[i];
//     }
// }

// void krnl_top(int* a, int* b, int* c, int size) {

//     #pragma HLS INTERFACE m_axi port=a bundle=gmem1
//     #pragma HLS INTERFACE m_axi port=b bundle=gmem1
//     #pragma HLS INTERFACE m_axi port=c bundle=gmem2
//     #pragma HLS INTERFACE s_axilite port=size

//     krnl(a, b, c, size);
// }


void krnl(
            hls::stream<int> &a, 
            hls::stream<int> &b, 
            hls::stream<int> &c) {
    #pragma HLS INTERFACE axis port = a
    #pragma HLS INTERFACE axis port = b 
    #pragma HLS INTERFACE axis port = c 

    // for (int i = 0; i < DATA_SIZE; i++) {
    //     #pragma HLS UNROLL //factor=2
    //     c[i] = a[i] + b[i];
    // }

    int aT, bT, cT; 

    a.read(aT);
    b.read(bT);
    c.write(aT + bT);


}
