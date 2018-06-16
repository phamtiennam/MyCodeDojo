/*
Description:
 A non-empty array of length  n  is called an array of all possibilities
if it contains all numbers between 0 and n - 1 inclusive. 

Write a method named isAllPossibilities that accepts an integer array 
and returns 1 if the array is an array of all possibilities, 
otherwise it returns 0.

Examples {1, 2, 0, 3} is an array of all possibilities,
{3, 2, 1, 0} is an array of all possibilities,
{1, 2, 4, 3} is not an array of all possibilities, (because 0 not included and 4 is too big),
{0, 2, 3} is not an array of all possibilities, (because 1 is not included),
{0} is an array of all possibilities,
{} is not an array of all possibilities (because array is empty).

If you are programming in Java or C#, the function signature is  
        int isAllPossibilities(int[ ] a)
If you are programming in C or C++, the function signature is  
        int isAllPossibilities(int a[ ], int len)
where len is the number of elements in the array.
*/

#include<iostream>
using namespace std;

int isAllPossibilities(int a[], int len)
{
  int retVal=0,count=0;
  int b[len];
 
  if((len < 0)||(a == NULL))
  {
    cout<<"Invalid input Parameters"<<endl;
    retVal=0;
    return retVal;
  }
  
  if(len>1)
  {
    for(int i=0;i<len;i++)
    {
      b[i] = -1;
    }
    
    for(int i=0;i<len;i++)
    {
      if( (a[i] >= 0) && (a[i] < len) )
      {
        if(b[a[i]] == -1)
        {
          b[a[i]] = a[i];
          count++;
        }
      }
      else
      {
        break;
      }
    }
    
    if(count == len)
    {
      retVal = 1;  
      return retVal;
    }
  }
  else
  {
    if((len == 1) && (a[0] == 0))
    {
      retVal = 1;
      return retVal;
    }
  }
  return retVal;
}


int main()
{
  int a[1] = {0};
  cout<<"a[1] = {0} :"<<isAllPossibilities(a,1)<<endl;
  
  
  int a1[1] = {1};
  cout<<"a1[1] = {0} :"<<isAllPossibilities(a1,1)<<endl;
  
  int a2[] = {};
  cout<<"a2[] = {} :"<<isAllPossibilities(a2,0)<<endl;
  
  int a3[4] = {1,2,3,0};
  cout<<"a3[4] = {1,2,3,0} :"<<isAllPossibilities(a3,4)<<endl;
  
  int a4[4] = {3,2,1,0};
  cout<<"a4[4] = {3,2,1,0} :"<<isAllPossibilities(a4,4)<<endl;
  
  int a5[4] = {1,2,4,3};
  cout<<"a5[4] = {1,2,4,3} :"<<isAllPossibilities(a5,4)<<endl;
  
  int a6[3] = {0,2,3};
  cout<<" a6[3] = {0,2,3}: "<<isAllPossibilities(a6,3)<<endl;
  
  int b[] = {0,1,3,1,4,5,7,8,7};
  cout<<" b[] = {0,1,3,1,4,5,7,8,7}: "<<isAllPossibilities(b,9)<<endl;
  
  return 0;
}
