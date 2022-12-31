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
	{
		// New scope 
		std::weak_ptr<UDT> ptr2 = ptr1;
		// reference count updated
		std::cout << "Use count inside scope: " << ptr2.use_count() << std::endl;
	} // ptr2 is now 'freed'

	// Then we check our updated reference count
	std::cout << "Use count outside scope: " << ptr1.use_count() << std::endl;
	return 0;


}
