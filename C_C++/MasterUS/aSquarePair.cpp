/*
Define a square pair to be the tuple <x, y> where x and y are positive, non-zero integers,
x<y and x + y is a perfect square.
A perfect square is an integer whose square root is also an integer,
e.g. 4, 9, 16 are perfect squares but 3, 10 and 17 are not.

Write a function named countSquarePairs that takes an array and returns the number of square pairs 
that can be constructed from the elements in the array.

For example, if the array is {11, 5, 4, 20} the function would return 3 because the only square
pairs that can be constructed from those numbers are <5, 11>, <5, 20> and <4, 5>.
You may assume that there exists a function named isPerfectSquare that returns 1 if its argument is a 
perfect square and 0 otherwise. E.G., isPerfectSquare(4) returns 1 and isPerfectSquare(8) returns 0.

If you are programming in Java or C#, the function signature is
int countSquarePairs(int[ ] a)
If you are programming in C++ or C, the function signature is
int countSquarePairs(int a[ ], int len)  where len is the number of elements in the array.
You may assume that there are no duplicate values in the array, i.e, you don't have to deal with an array like {2, 7, 2, 2}.
*/

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int isPerfectSquare(int n)
{
  int retVal = 0;
  int tmp = sqrt(n);
  if(tmp*tmp == n)
  {
    retVal = 1;
  }
  return retVal;
}

int countSquarePairs(int a[],int len)
{
  int count = 0;
  cout<<"check array a["<<len<<"]:\n";
  if(len>=2)
  {
    /*Sort array first*/
    sort(a,a+len);
    for(int i=0;i<len;i++)
    {
      if(a[i] > 0)
      {
        for(int j=i+1;j<len;j++)
        {
          if(isPerfectSquare(a[i]+a[j]))
          {
            count++;
            cout<<"Pair ["<<a[i]<<","<<a[j]<<"]\n";
          }
        }
      }
      else
      {
        //cout<<a[i]<<" is not positive integer\n";
      }
    
    } 
  }
  else
  {
    cout<<"Length of array is not valid\n";
  }
  cout<<"-->count:"<<count<<endl;
  return count;
}

int main()
{
  int a[1] = {9};
  countSquarePairs(a,1);
  
  int a1[10] = {9,0,2,-5,7,8,-22,-32,16,5};
  countSquarePairs(a1,10);
  
}