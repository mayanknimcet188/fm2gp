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

// since now we have the optimized version of our multiply_accumulate algorithm
// we can now have this as a helper funcion and call it from our original multiply interface multiply(a,b)
int multiply(int n, int a) {
	if(n == 1) return a;
	return multiply_accumulate_improved_strictly_tail_recursive(a, n-1, a);
}

// the worst case for above algorithm is when n is even, as n-1 contains all 1 bits
// so we will avoid this by doing some advance work when n is even 
// halving it and doubling a unitl n is odd before calling the algorithm
int multiply_improved_when_n_is_even(int n, int a) {
	while(!odd(n)) {
		a = a + a;
		n = half(n);
	}
	if(n == 1) return a;
	return multiply_accumulate_improved_strictly_tail_recursive(a, n-1, a);
}

// FINAL VERSION
// since in the above version we do one unnecessary test for odd(n) in our helper function, 
// since we are already calling it with an even number
// so we do one more halving and doubling before calling it, to compensate the no of operations
int multiply_final(int n, int a) {
	while(!odd(n)) {
		a = a + a;
		n = half(n);
	}
	if(n == 1) return a;
	// even(n-1) => n-1 != 1
	return multiply_accumulate_improved_strictly_tail_recursive(a, half(n-1), a + a);
}
#endif
