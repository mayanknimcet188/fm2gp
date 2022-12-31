#ifndef MULTIPLY_ACCUMULATE
#define MULTIPLY_ACCUMULATE

#include "utils.h"

int multiply_accumulate(int r, int n, int a) {
	if(n == 1) return r+a;
	if(odd(n)) {
		return multiply_accumulate(r+a, half(n), a + a);
	} else {
		return multiply_accumulate(r, half(n), a + a);
	}
}

// since the two recusrive calls for odd or even differ only in the value of the calling argument 'r'
// if n is odd: r <- r + a ,else just pass 'r'
// this function is also tail-recusrive
int multiply_accumulate_improved(int r, int n, int a) {
	if(n == 1) return r+a;
	if(odd(n)) r = r + a;
	return multiply_accumulate_improved(r, half(n), a + a);
}

// if n is even, we don't need to check if it's 1, thereby reducing comparisions with 1 by a factor of 2
// we can check for oddness first
// tail recusrive
// TODO: take the singleton and instrumented class from Alex's lecture and count the number of operations in both the functions
int multiply_accumulate_improved_tail_recursive(int r, int n, int a) {
	if(odd(n)) {
		r = r + a;
		if(n == 1) return r;
	}
	return multiply_accumulate_improved_tail_recursive(r, half(n), a + a);
}

// another iteration for improvement is to make the function strictly tail recusrive
// it's easier to convert a recusrive procedure to iterative to remove the function call overhead that we have normally in recursion
// if we first make the tail recursive procedure strictly tail recusrive
// strictly tail recursive means the function in which all the tail recusrive calls
// are done with the formal parameters of the procedure being the corresponding arguments
int multiply_accumulate_improved_strictly_tail_recursive(int r, int n, int a) {
	if(odd(n)) {
		r = r + a;
		if(n == 1) return r;
	}
	n = half(n);
	a = a + a;
	return multiply_accumulate_improved_strictly_tail_recursive(r, n, a);
}

// now we convert the above strictly tail recursive procedure to iterative procedure
// we just have to replace the tail recursion with a while(true) construct
int multiply_accumulate_iterative(int r, int n, int a) {
	while(true) {
		if(odd(n)) {
			r = r + a;
			if (n == 1) return r;
		}
		n = half(n);
		a = a + a;
	}
}
#endif
