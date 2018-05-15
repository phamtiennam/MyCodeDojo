/*
Write a function named primeCount 
with signatureint primeCount(int start, int end);
The function returns the number of primes between start and end inclusive. 
Recall that a prime isa positive integer greater than 1 whose only integer factors  are 1 and itself.
*/
#include <iostream>
#include <vector>

using namespace std;

bool isPrimeNo(int numb)
{
	bool boolVal=true;
	if(numb > 1)
	{
		for (int i=2 ;i <= numb/2;i++ )
		{
			if(numb%i == 0)
			{
				boolVal=false;
				break;
			}
		}
	}
	else
	{
		boolVal=false;
	}
	
	return boolVal;
}

vector <int> primeCount(int start, int end)
{
	vector<int> V;
	if (end >> 2)
	{
		for(int i=start;i<=end;i++)
		{
			if(isPrimeNo(i))
			{
				V.push_back (i);
			}
		}
	}
	return V;
}

int main()
{
	int start,end;
	std::vector<int> v;

	cout<<"Enter start & end number:";
	cin>>start>>end;

	v = primeCount(start,end);
	std::cout << "Total  " << int(v.size()) << " prime numbers.\n";
	if(int(v.size()) > 0)
	{
		for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
		{
    		cout << *i << "\n";
		}
	}
	
	return 0;
}