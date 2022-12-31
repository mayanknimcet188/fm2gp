#ifndef EGYPTIAN_MULTIPLICATION_H
#define EGYPTIAN_MULTIPLICATION_H
#include<iostream>
#include "utils.h"

int egyptian_multiplication(int n, int a) {
	if(n == 1) return a;
	int result = egyptian_multiplication(half(n), a + a);
	if(odd(n)) result = result + a;
	return result;
}

#endif

