#include "krnl.hpp"
#include <iostream>
#include "hls_stream.h"

int main() {

    int a = 1; 
    int b = 1;
    int c;

    hls::stream<int> aS;
    hls::stream<int> bS;
    hls::stream<int> cS;

    aS.write(a);
    bS.write(b);
    krnl(aS, bS, cS);
    cS.read(c);

    std::cout << "C  = " << c << std::endl; 

}