#include<iostream>
#include<string>

// Pure virtual function
class Printable {
	public:
		virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
	public:
		virtual std::string GetName() { return "Entity"; };
		std::string GetClassName() { return "Entity"; }
};

class Player : public Entity {
 private:
	std::string m_Name;
 public:
	Player(const std::string& name) : m_Name(name) {}

	std::string GetClassName() { return "Player"; }
	std::string GetName() override { return m_Name;}
};

void PrintName(Entity* entity) {
	std::cout << entity->GetName() << std::endl;	
}

void Print(Printable* obj) {
	std::cout << obj->GetClassName() << std::endl;
}

int main() {

	Entity* e = new Entity();
	// PrintName(e);

	Player* p = new Player("Player 2"); 
	// PrintName(p);

	Print(e);
	Print(p);
	return 0;

}
