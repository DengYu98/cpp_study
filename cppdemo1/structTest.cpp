//
// Created by Lenovo on 2021/11/22.
//

#include <iostream>

using namespace std;

struct Header {
//    unsigned char a : 5;
//    unsigned char b : 2;
//    unsigned char c : 1;

    uint32_t a;
    uint32_t b;
    uint32_t c;
};

int main()
{
    unsigned char* base =  new unsigned char[4];
    base[0] = 0x65;
    base[1] = 0x61;
    base[2] = 0x41;
    base[3] = 0x62;
    Header * hdr = (Header *)&base[0];
//    cout << (int) (hdr -> a & 0xff) << endl;
//    cout << (int)hdr -> a  << endl;
    printf("[%d]\n",(unsigned char)hdr -> a);
    cout << (int)(hdr -> b & 0x1f)<< endl;



    return 0;
}

