#ifndef STUDENT_HPP
#define STUDENT_HPP
#include<string>
// User Defined Type - Student
class Student {
	public:
	    // Actions - Constructor
	    Student();
		// Action - Desctructor
		~Student();
		// Action - Print the student name
		void printName();
	public:
		std::string m_name;
};

#endif
