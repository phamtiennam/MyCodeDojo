/*
A Fibonacci number is a number in the sequence 1, 1, 2, 3, 5, 8, 13, 21,.... 

Note that first two Fibonacci numbers are 1 and any Fibonacci number other 
than the first two is the sum ofthe previous two Fibonacci numbers.
For example, 2 = 1 + 1, 3 = 2 + 1, 5 = 3 + 2 and so on.

Write a function named isFibonacci that returns 1 if its integer argument 
is a Fibonacci number,otherwise it returns 0.

The signature of the function is
int isFibonacci (int n)
*/
#include<iostream>
#include <math.h>       /* sqrt */

using namespace std;
bool isPerfectSquare(int x)
{
  int tmp = sqrt(x);
  return (tmp*tmp == x);
}

int isFibonacci(int n)
{
  return(isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n -4 ));
}


int main()
{
  cout<<"41:"<<isFibonacci(41)<<endl;
  cout<<"1:"<<isFibonacci(1)<<endl;
  cout<<"8:"<<isFibonacci(8)<<endl;
  cout<<"13:"<<isFibonacci(13)<<endl;
  return 0;
}