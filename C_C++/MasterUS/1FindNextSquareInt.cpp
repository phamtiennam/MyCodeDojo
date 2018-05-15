#include <iostream>
#include <cmath>

using namespace std;

int square_root(int num)
{
	int ans;
	ans=pow(num,0.5);
	//cout<<"\n Square of "<<num<<" is:"<<ans<<"\n";
	return ans;
}

int main()
{
	int num;
	cout<<"Enter any Num: ";
	cin>>num;
	cout<<"next perfect Square of"<<num<<" is:"<<pow(square_root(num)+1,2)<<"\n";

	return 0;
}