#include<iostream>
#include<string>
#include "array.hpp"

int main() {	
	
	Array myArray;
	
	myArray.setData(0, 1000);
	myArray.setData(1, 77);
	myArray.setData(2, 45);

	myArray.printingData();

	Array myArray2 = myArray;
	myArray2.printingData();
	
	Array myArray3;
	myArray3 = myArray;
	myArray3.printingData();
	return 0;
}
