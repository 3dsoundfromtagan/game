#include <iostream>

using namespace std;

class Animal {
public:
	char *name;
	float weight;
	
	Animal(char* _name, float _weight) : name(_name), weight(_weight) {
		cout << "Animal constructor..." << endl;
	};	

	~Animal() {
		cout << "Animal destructor..." << endl;
	};
	
	void talk(){
		cout << "Animal talks!" << endl;
	};
};

class Dog: public Animal {
public:
	Dog(char* _name, float _weight): Animal(_name, _weight){
		cout << "Dog constructor..." << endl;
	};

	~Dog(){
		cout << "Dog destructor..." << endl;
	};
	
	void talk() {
		cout << "Bow-wow!" << endl;
	};
};


class Cat: public Animal {
public:
	Cat(char* _name, float _weight): Animal(_name, _weight){
		cout << "Cat constructor..." << endl;
	};

	~Cat(){
		cout << "Cat destructor..." << endl;
	};

	void talk() {
		cout << "Meow!" << endl;
	};
};


int main() {
	Dog spike("Spike", 5.0);
	Cat tom("Tom", 4.1);
	
	spike.talk();
	tom.talk();
	
	return 0;
}
