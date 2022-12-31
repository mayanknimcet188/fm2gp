#include<iostream>
#include "array.hpp"


Array::Array() {
   std::cout << "Constructor called" << std::endl;
   data = new int[10];
   for(int i=0; i<10; i++) {
	data[i] = i*i;
	}
}
		
void Array::printingData() {
	for(int i=0; i<10; i++) {
		std::cout << data[i] << std::endl;
	}
}
		
Array::~Array() {
	delete[] data;
}

Array::Array(const Array& rhs) {
	std::cout << "Copy Constructor called" << std::endl;
	delete[] data;
	data = new int[10];
	for(int i=0; i<10; ++i) data[i] = rhs.data[i];
}

Array& Array::operator=(const Array& rhs) {
	std::cout << "Copy Assignment Operator" << std::endl;
			
	if(&rhs == this) {
		// don't want to make a copy of the object itself
		return *this; // return the object itself again
	}

    delete[] data;
	data = new int[10];
	for(int i=0; i<10; ++i) data[i] = rhs.data[i];		
	   return *this;
    }

void Array::setData(int index, int value) {
	data[index] = value;
}
		


