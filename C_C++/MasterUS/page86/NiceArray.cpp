/*
 A Nice array is defined to be an array where for every value n in the array, there is also an 
element n­1 or n+1 in the array. 
For example, {2, 10, 9, 3} is a Nice array because
2 = 3­1
10 = 9+1
3 = 2 + 1
9 = 10 ­1
Other Nice arrays include {2, 2, 3, 3, 3}, {1, 1, 1, 2, 1, 1} and {0, ­1, 1}.The array {3, 4, 5, 7} is not a Nice array because of the value 7 which requires that the array contains
either the value 6 (7­1) or 8 (7+1) but neither of these values are in the array.
Write a function named isNice that returns 1 if its array argument is a Nice array. Otherwise it returns 
a 0.
If you are programming in Java or C#, the function signature is
   int isNice(int[ ] a)
If you are programming in C or C++, the function signature is
   int isNice(int a[ ], int len) where len is the number of elements in the array.
April 4, 2015
*/
#include <iostream>
using namespace std;
int rearrange(int a[],int len)
{
  int tmp;
  for(int i=0;i<len-1;i++)
  {
    for(int j=i+1;j<len;j++)
    {
      if(a[j]<a[i])
      {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
}

int printArray(int a[],int len)
{
  for(int i=0;i<len;i++)
  {
    cout<<a[i]<<" ";
  }
    cout<<endl;
}

int isNice(int a[],int len)
{
  int equal_one = 0;
  int bigger_than_one = 0;
  int sub,i=0;
  rearrange(a,len);
  while(i<len-1)
  {
    sub = a[i+1] - a[i];
    if(sub > 1)
    {
      bigger_than_one = 1;
      break;
    }
    else if(sub == 1)
    {
      equal_one = 1;
      i = i+2;
    }
    else
    {
      i++;
    }
  }
  
  return((equal_one == 1)&&(bigger_than_one == 0));
}

int testArray(int a[],int len)
{
  printArray(a,len);
  cout<<isNice(a,len)<<endl;
  return 1;
}
int main()
{
  int a[4] = {2,10,9,3};
  int b[6] = {1,1,1,2,1,1};
  int c[5] = {2,2,3,3,3};
  int d[3] = {0,1,1};
  int e[4] = {3,4,5,7};
  testArray(a,4);
  testArray(b,6);
  testArray(c,5);
  testArray(d,3);
  testArray(e,4);
  return 0;
}