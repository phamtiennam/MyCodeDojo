#include<iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int Reverse(int num)
{
  int out = 0,tmp;
  while (num != 0)
  {
    tmp = num % 10;
    out = out*10 + tmp;
    num = num / 10;
  }
  return out;
}
int main()
{
	int count=0;
  int i,j,k;
	cout << "Numbers: ";
	cin >>i>>j>>k;
  
  if((j>=i)&&(i>=1))
  {
        int tmp=i;
        while(tmp<=j)
        {   
            if(abs(tmp - Reverse(tmp))%k == 0)
            {
                count++;
            }
            tmp++;
        }
  }
  
  cout<<"Count:"<<count<<endl;
	return 0;
}