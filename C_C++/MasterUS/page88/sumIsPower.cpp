/*
Question 2. Write a function sumIsPower with signatuare 
boolean sumIsPower(int[] arr)                       
which outputs true if the sum of the elements in the input array arr is a power of 2, false otherwise. Recall that
the powers of 2 are 1, 2, 4, 8, 16, and so on. In general a number is a power of 2 if and only if it is of the form 2 n
for some nonnegative integer n. You may assume (without verifying in your code) that all elements in the array
are positive integers. If the input array arr is null, the return value should be false.
Examples:  sumIsPower({8,8,8,8}) is true since 8 + 8 + 8 + 8 = 32 = 2 5 .  sumIsPower({8,8,8})  is false, since 8
+ 8 +8 = 24, not a power of 2. 
*/

#include<iostream>
using namespace std;

bool sumIsPower(int a[],int len)
{
  bool retVal = true;
  int sum=0;
  if(len > 0)
  {
    for(int i=0;i<len;i++)
    {
      sum += a[i];
    }
    while(sum != 1)
    {
      if((sum % 2) == 0)
      {
        sum = sum / 2;
      }
      else
      {
        retVal = false;
        break;
      }
    }
  }
  else
  {
    retVal = false;
  }
  
  return retVal;
}

int test(int a[],int len)
{
  cout<<"{";
  for(int i = 0; i < len; i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<"}:"<<sumIsPower(a,len)<<endl;
  return 0;
}

int main()
{
  int a[] = {8,8,8};
  test(a,sizeof(a)/sizeof(a[0]));
  return 0;
}