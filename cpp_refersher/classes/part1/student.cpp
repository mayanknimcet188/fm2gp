#include<iostream>
#include "student.hpp"

// Action - Constructor
Student::Student() {
	std::cout << "Constructor" << std::endl;
}

// Action - Destructor
Student::~Student() {
	std::cout << "Destructor" << std::endl;
}

void Student::printName() {
	std::cout << "Name: " << m_name << std::endl;
}

