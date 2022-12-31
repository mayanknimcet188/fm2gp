#include<iostream>
#include<string.h>
#include<memory.h>

class String {
	public:
		String() = default;
		String(const char* string)
		{
			printf("Created\n");
			size = strlen(string);
			data = new char[size];
			memcpy(data, string, size);
		}
		// copy constructor
		String(const String& other) {
			printf("Copied!\n");
			size = other.size;
			data = new char[size];
			memcpy(data, other.data, size);
		}
		
		// move constructor
		String(String&& other) noexcept
		{
				printf("Moved!\n");
				size = other.size;
				data = other.data;
				
				// hollow object for the old temporary string
				other.size = 0;
				other.data = nullptr;
		}

		~String() {
			printf("Destroyed\n");
			delete data;
		}

		void Print() {
			for(uint32_t i = 0; i < size; ++i) {
				printf("%c", data[i]);
			}
			printf("\n");
		}
	private:
		char* data;
		uint32_t size;

};


class Entity {
	public:
		Entity(const String& name) : name(name) {
		}
		void PrintName() {
			name.Print();
		}

		Entity(String&& name) : name((String&& )name) {}
	private:
		String name;
};

int main() {
	Entity entity("Mayank");
	entity.PrintName();
	return 0;
}
