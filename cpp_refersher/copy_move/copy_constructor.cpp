#include<iostream>
#include<string.h>

class String {
	private:
		char* buffer;
		unsigned int size;
	public:
		String(const char* string) {
			size = strlen(string);
			buffer = new char[size+1];
			memcpy(buffer, string, size);
			buffer[size] = 0;
		}
        
		String(const String& other)
			: size(other.size) 
		{
			buffer = new char[size + 1];
			memcpy(buffer, other.buffer, size + 1);
		}

		~String()
		{
			delete[] buffer;
		}
		
		char& operator[](int index) {
			return buffer[index];
		}

		friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	
	stream << string.buffer;
	return stream;
}

int main() {
	String string = "mayank";
	String second = string;

	second[2] = 'a';

	std::cout << string << std::endl;
	std::cout << second << std::endl;
}
