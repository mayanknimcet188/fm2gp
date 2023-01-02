#include<iostream>
#include "egyptian_multiplication.h"
#include "normal_multiply.h"
#include "multiply_accumulate.h"

int main() {
	int n, a;
	std::cin >> n >> a;
	std::cout << "Egyptian Multiplication [ " << n << "*" << a << " ] = " << egyptian_multiplication(n,a) << std::endl;
	std::cout << "Normal Multiplication [ " << n << "*" << a << " ] = " << normal_multiply(n,a) << std::endl;
	std::cout << "Multiply Accumulate [ " << n << "*" << a << " ] = " << multiply_accumulate(0,n,a) << std::endl;	
	std::cout << "Multiply Accumulate Improved [ " << n << "*" << a << " ] = " << multiply_accumulate_improved(0,n,a) << std::endl;
	std::cout << "Multiply Accumulate Improved Tail Recursive [ " << n << "*" << a << " ] = " << multiply_accumulate_improved_tail_recursive(0,n,a) << std::endl;
	std::cout << "Multiply Accumulate Strictly Tail Recursive [ " << n << "*" << a << " ] = " << multiply_accumulate_improved_strictly_tail_recursive(0,n,a) << std::endl;
	std::cout << "Multiply Accumulate Iterative [ " << n << "*" << a << " ] = " << multiply_accumulate_iterative(0,n,a) << std::endl;
	std::cout << "Multiply Accumulate Original Interface [ " << n << "*" << a << " ] = " << multiply(n,a) << std::endl;
	std::cout << "Multiply Accumulate Original Improved when n is even [ " << n << "*" << a << " ] = " << multiply_improved_when_n_is_even(n,a) << std::endl;
	std::cout << "Multiply Accumulate Final Version [ " << n << "*" << a << " ] = " << multiply_final(n,a) << std::endl;
	return 0;
}

