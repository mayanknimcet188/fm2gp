#include<iostream>
#include<string>

using namespace std;

template<typename T>
class Vector {
	private:
		T* elem; // elem points to an array of sz elements of type T
		int sz; 
	public:
		Vector(int s); // constructor: establish invariant, acquire resources 
		~Vector() { delete[] elem; } // destructor: release resources

		// ...copy and move operations
		
		T& operator[](int i); //for non-const Vectors
		const T& operator[](int i) const; //for const Vectors
		void write() const; // print the vector
		int size() const { return sz; }
};

template<typename T>
Vector<T>::Vector(int s) {
	if(s<0) { cout << "Negative length" << endl; }
	elem = new T[s];
	sz=s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const {
	if(i<0 || size()<=i) { cout << "Can't access out of range elements" << endl; return -111; }
	return elem[i];
}

template<typename T>
void Vector<T>::write() const { // vector of some strings
	for(int i=0; i!=sz;++i) {
		cout<< elem[i] << '\n';
	}
}

int main() {
	
	const Vector<string> vs(2);// vector of 2 strings
	vs.write();
	return 0;
};
