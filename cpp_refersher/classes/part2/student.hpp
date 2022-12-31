#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<string>

// User Defined Type - Student
class Student {
	public:
	    // Actions - Constructor
	    Student();
		// Named Constructor
		Student(std::string name);
		// Action - Desctructor
		~Student();
		// Action - Print the student name
		void printName();
	private:
		std::string m_name;
};

#endif
