#include<iostream>

int add(int x, int y) {
	return x+y;
}

int multiply(int x, int y) {
	return x*y;
}

int main() {

	// function pointer for functions: int name(int, int)
	int (*op)(int, int);
	std::cout << "1. Add" << std::endl;
	std::cout << "2. Multiply" << std::endl;
	std::cout << "Enter the operation: " << std::endl;
	int opInput;
	std::cin >> opInput;
	std::cout << "Enter the operands: " << std::endl;
	int x, y;
	std::cin >> x >> y;

	switch(opInput) {
		case 1: 
			op=add;
			break;
		case 2:
			op=multiply;
			break;
		default:
			op=add;
	}

	std::cout << "Result: " << op(x,y) << std::endl;

	return 0;
}
