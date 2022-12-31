#ifndef UTILS_H
#define UTILS_H

#include<iostream>

bool odd(int n) { return n & 0x1; } // checking the last bit
int half(int n) { return n >> 1; } // right shifting the bits

#endif
