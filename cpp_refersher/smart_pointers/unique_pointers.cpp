#include<iostream>
#include<memory>

// User Defined type
class UDT {
	public:
		// Constructor (Called on Creation)
		UDT() { std::cout << "UDT Created" << std::endl; }
		// Destructor (Called on Destruction)
		~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};
 
int main() {
	
	// creating an unique pointer
	std::unique_ptr<UDT> ms = std::unique_ptr<UDT>(new UDT);
	
	// creating an 'array' that is pointed to, by one unique pointer
	std::unique_ptr<UDT[]> udt_arr = std::unique_ptr<UDT[]>(new UDT[5]);
	
	// equivalent to the above line, more intuitive is
	// make_unique is based on th factory design pattern
	std::unique_ptr<UDT[]> udt_array = std::make_unique<UDT[]>(10);

	// this is not allowed as copy constructor is not available for unique pointers
	// std::unique_ptr<UDT[]> new_arr = udt_arr;
	
	// we are allowed to move a unique pointer
	std::unique_ptr<UDT[]> moved_arr = std::move(udt_arr);
	return 0;

}
