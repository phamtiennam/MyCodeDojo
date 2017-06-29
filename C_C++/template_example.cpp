
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:example for using template
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_06_29
#include <iostream>

template <class Type> 
void Swap( Type &x, Type &y)
{
Type Temp = x;
x = y; 
y = Temp;
}

int main()
{
	int x = 5, y = 10;
	float a = 5.5f, b = 3.0f;


	std::cout<<"org x,y="<<x<<";"<<y<<std::endl;
	Swap(x, y);
	std::cout<<"Swap:"<<x<<";"<<y<<std::endl;
	std::cout<<"org a,b="<<a<<";"<<b<<std::endl;
	Swap(a, b);
	std::cout<<"Swap:"<<a<<";"<<b<<std::endl;
	return 0;
}

