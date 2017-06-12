
/*####################################################################
#Description:To understand virtual function in C++
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
virtual void eat() { std::cout << "I'm eating generic food.\n"; }
};

class Cat : public Animal
{
	public:
virtual void eat() { 
		std::cout << "I'm eating a rat.\n"; 
	}
};

void func(Animal *xyz){ 
	xyz->eat();
}

int main()
{
	Animal *animal ;
	Cat *cat;
	//animal->eat();
	//cat->eat();
	func(animal);
	func(cat);
	return 0;
}
