#pragma once
#include "hls_stream.h"
#define DATA_SIZE 2
typedef int data_t;

void krnl(
            hls::stream<int> &a, 
            hls::stream<int> &b, 
            hls::stream<int> &c);