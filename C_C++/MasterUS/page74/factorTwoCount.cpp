/*
1.Write a function named factorTwoCount that returns the number of times that 2 divides the 
argument.

For example,
factorTwoCount(48) returns 4 because 
48/2 = 24
24/2 = 12
12/2 = 6
6/2 = 3
2 does not divide 3 evenly.

Another example:
factorTwoCount(27) returns 0 because 2 does not divide 27.

The function signature is
   int factorTwoCount(int n);
   
*/

#include <iostream>
using namespace std;
int factorTwoCount(int n)
{
  int count = 0;
  while((n%2) == 0)
  {
    count++;
    n=n/2;
  }
  return count ;
}

int main()
{
  count<<"48:"<<factorTwoCount(48)<<endl;
  count<<"27:"<<factorTwoCount(27)<<endl;
  count<<"-48:"<<factorTwoCount(-48)<<endl;
  return 0;
}