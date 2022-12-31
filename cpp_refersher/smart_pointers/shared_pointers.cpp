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
	
	std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
	std::shared_ptr<UDT> ptr2 = ptr1;

	std::cout << "Use count: " << ptr1.use_count() << std::endl;
	return 0;


}
