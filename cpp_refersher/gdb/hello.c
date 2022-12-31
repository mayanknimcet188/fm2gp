#include<stdio.h>

int* px = NULL;

void foo() {
	printf("foo\n");
}

int main(void) {
	
	char* name = "mayank";
	char* name2 = "mayank2";

	printf("my name is: %s\n", name);
	
	foo();

	name = name2;

	return 0;
}
