#include<iostream>
#include<string>
#include "student.hpp"

// Action - Constructor
Student::Student() {
	m_name = "New Student";
	std::cout << "Constructor" << std::endl;
	std::cout << "Student with name: " << m_name << " created." << std::endl; 
}

Student::Student(std::string name) {
	m_name = name;
	std::cout << "Constructor: " << std::endl;
	std::cout << "Student with name: " << m_name << " created." << std::endl;
}

// Action - Destructor
Student::~Student() {
	std::cout << "Destructor" << std::endl;
}

void Student::printName() {
	std::cout << "Name: " << m_name << std::endl;
}

