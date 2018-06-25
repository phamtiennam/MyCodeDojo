 /*
 A normal number is defined to be one that has no odd factors, except for 1 and possibly itself.
Write a method named isNormal that returns 1 if its integer argument is normal, otherwise it returns 0. The
function signature is 
int isNormal(int n)
Examples: 1, 2, 3, 4, 5, 7, 8 are normal numbers. 6 and 9 are not normal numbers since 3 is an odd factor. 10 is
not a normal number since 5 is an odd factor. 
*/
#include<iostream>
#include <stdlib.h>     /* abs */
using namespace std;

int isNormal(int n)
{
  int retVal = 1;
  int tmp = 2;
  n = abs(n);
  while(tmp < n)
  {
    if((n%tmp == 0)&&(tmp%2 != 0))
    {
      retVal = 0;
    }
    tmp++;
  }
  return retVal;
}

int main()
{
  
  int array[] = {1,2,3,4,5,7,8,9,6,22,15,27,45,21,-33};
  int len = sizeof(array)/sizeof(array[0]);\
  //cout<<len<<endl;
  for(int i=0;i<len;i++)
  {
    cout<<array[i]<<" isNormal :"<<isNormal(array[i])<<endl;
  }
}