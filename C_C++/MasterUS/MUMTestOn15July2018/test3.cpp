#include<iostream>
using namespace std;


int computeWeightedSumNam(int a[],int len)
{
  int sum = 0,sumOdd = 0,sumEven = 0;
  for(int i=0;i<len;i++)
  {
    if(a[i]%2 == 0)
    {
      sumEven += a[i];
    }
    else
    {
      sumOdd += a[i];
    }
  }
  sum = 2*sumEven + 3*sumOdd;
  return sum;
}

int computeWeightedSum(int a[], int len)
{
	int sum =0;
	for(int i = 0; i < len; i++)
	{
		if(a[i]%2 == 0)
		{
			sum += 2*a[i];
		}
		else
		{
			sum += 3*a[i];
		}
	}
	return sum;
}

int main()
{
  int a[5] = {1, 2, 3, 4, 5};
  cout<<computeWeightedSum(a,5)<<endl;
  
  int b[3] = {1, 3, 5};
  cout<<computeWeightedSum(b,3)<<endl;
  
  int c[3] = {2, 4, 6};
  cout<<computeWeightedSum(c,3)<<endl;
  int d[1] = {1};
  cout<<computeWeightedSum(d,1)<<endl;
  
  int e[1] = {2};
  cout<<computeWeightedSum(e,1)<<endl;
  
  int f[5] = {0, 0, 0, 0, 0};
  cout<<computeWeightedSum(f,5)<<endl;
  
  return 0;
}