#include<iostream>
#include<string>

class Array {
	public:
		Array() {
			std::cout << "Constructor called" << std::endl;
			
			data = new int[10];
			for(int i=0; i<10; i++) {
				data[i] = i*i;
			}
		}
		
		void printingData() {
			for(int i=0; i<10; i++) {
				std::cout << data[i] << std::endl;
			}
		}
		
		~Array() {
			delete[] data;
		}
		
		// Copy Constructor
		Array(const Array& rhs) {
			std::cout << "Copy Constructor called" << std::endl;
			delete[] data;
			data = new int[10];
			for(int i=0; i<10; ++i) data[i] = rhs.data[i];
		}

		// Copy assignment operator
		// Object is already constructed, we are just
		// making a copy later (myArray2 = myArray)
		Array& operator=(const Array& rhs) {
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

		void setData(int index, int value) {
			data[index] = value;
		}

	private:
		int* data;
		
};

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
