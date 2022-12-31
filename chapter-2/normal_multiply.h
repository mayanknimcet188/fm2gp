#ifndef MULTIPLY_H
#define MULTIPLY_H
#include<iostream>

// add a n times; Complexity: O(n)
int multiply(int n, int a) {
	if(n == 1) return a;
	return multiply(n-1, a) + a;
}

#endif

