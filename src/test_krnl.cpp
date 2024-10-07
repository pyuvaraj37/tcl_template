#include "krnl.hpp"
#include <iostream>

int main() {

    int n = 2; 
    int a[n] = {1, 1}; 
    int b[n] = {1, 1};
    int c[n];

    krnl(a, b, c);

    std::cout << "C  = " << c[0] << std::endl; 
    std::cout << "C  = " << c[1] << std::endl; 

}