#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {
	public:
		Array();	
		~Array();
		
		void printingData();		

		// Copy Constructor
		Array(const Array& rhs);

		// Copy assignment operator
		// Object is already constructed, we are just
		// making a copy later (myArray2 = myArray)
		Array& operator=(const Array& rhs);
		void setData(int index, int value);
	private:
		int* data;		
};

#endif
