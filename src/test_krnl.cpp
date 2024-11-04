#include "krnl.hpp"
#include <iostream>
#include "hls_stream.h"



// void test_krnl(
//     hls::stream<pkt256>& m_axis_tx_meta, 
//     hls::stream<pkt64>& m_axis_tx_data,
//     hls::stream<pkt64>& s_axis_tx_status,

//     hls::stream<pkt256>& m_axis_bram_write_cmd, 
//     hls::stream<pkt256>& m_axis_bram_read_cmd,
//     hls::stream<pkt512>& m_axis_bram_write_data,
//     hls::stream<pkt512>& s_axis_bram_read_data,

//     hls::stream<pkt64>& s_axis_update,
//     int myBoardNum,
//     int RDMA_TYPE, 
//     int exec, 
//     int *network_ptr
// );

int main() {

    int myBoardNum = 1, RDMA_TYPE = 4, exec = 1000000;
    int network_ptr[100];

    hls::stream<pkt256> s_axis_tx_meta; 
    hls::stream<pkt64> s_axis_tx_data;
    hls::stream<pkt64> m_axis_tx_status;

    hls::stream<pkt256> s_axis_bram_write_cmd; 
    hls::stream<pkt256> s_axis_bram_read_cmd;
    hls::stream<pkt512> s_axis_bram_write_data;
    hls::stream<pkt512> m_axis_bram_read_data;

    hls::stream<pkt64> m_axis_update;

    //Test HBM
    network_ptr[0] = exec;


    //Test BRAM
    pkt512 bram_data;
    bram_data.data = exec;
    m_axis_bram_read_data.write(bram_data);

    //Test Write-Through
    pkt64 wt_data;
    wt_data.data = exec; 
    m_axis_update.write(wt_data);

    test_krnl(
        s_axis_tx_meta,
        s_axis_tx_data,
        m_axis_tx_status,
        s_axis_bram_write_cmd,
        s_axis_bram_read_cmd,
        s_axis_bram_write_data,
        m_axis_bram_read_data,
        m_axis_update,
        myBoardNum, 
        RDMA_TYPE,
        exec,
        network_ptr
    );

}