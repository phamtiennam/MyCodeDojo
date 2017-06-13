
/*####################################################################
#Description:		To understand virtual function in C++

-->A virtual function is a member function in base class that you expect to redefine in derived classes.

Link reference: https://www.programiz.com/cpp-programming/virtual-functions

#Coder: NamPham
#Email: nampt282@gmail.com
#Date: 2017_06_12
####################################################################
####################################################################
*/
#include <iostream>
using namespace std;

class Animal
{
	public:
	virtual void eat() { std::cout << __func__ << "I'm eating generic food."<< endl; }
};

class Cat : public Animal
{
	public:
	void eat() { 
		std::cout << "I'm eating a rat." << endl; 
	}
};

class Dog : public Animal
{
	public:
	void eat() { 
		std::cout << __func__ << "I'm eating a shit." << endl; 
	}
};

void func(Animal *xyz){ 
	xyz->eat();
}

int main()
{
	Animal *animal = new Animal;
	Cat *cat = new Cat;
	Dog *mydog = new Dog;
	//animal->eat();
	//cat->eat();
	func(animal);
	func(cat);
	func(mydog);
	return 0;
}
