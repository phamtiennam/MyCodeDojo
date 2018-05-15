/*Description:
 * A Madhav array has the following property. 
   a[0] = a[1] + a[2] = a[3] + a[4] + a[5] = a[6] + a[7] + a[8] + a[9] = ...
   The length of a Madhav array must be n*(n+1)/2 for some n.
   
   Write a method named isMadhavArray that returns 1 if its array argument is a Madhav array, 
   otherwise it returns 0.
   
   If you are programming in Java or C# the function signature is
   int isMadhavArray(int[ ] a)
   
   If you are programming in C or C++, the function signature is
   int isMadhavArray(int a[ ], int len) where len is the number of elements in a.
 * 
 * */

#include <iostream>
#include <math.h>
using namespace std;


bool checkLength(int len)
{
  bool retVal = false;
  /*    Note
        n*(n+1)/2 = len
        n>0 --> n = (sqrt(8*len + 1) -1)/2
        if sqrt(8*len + 1) is integer value then n is valid
   */
   int tmp = sqrt(8*len + 1);
   if(tmp*tmp == (8*len +1))
   {
     retVal = true;
   }

  return retVal;
}

int isMadhavArray(int a[], int len)
{
    int retVal = 1;
    int Max_elements=2;
    int Cur_elements=0;
    int sum=0;
    
    if(checkLength(len))
    {
      //cout<<len<<" is valid length\n";

      for(int i=1;i<len;i++)
      {
        if(Cur_elements < Max_elements)
        {
          sum = sum + a[i];
          Cur_elements++;
          if(Cur_elements == Max_elements)
          {
            if(sum!=a[0])
            {
              retVal=0;
              break;
            }
            else
            {
              sum = 0;
              Max_elements++;
              Cur_elements=0;
            }
          }
        }
      }   
    }
    else
    {
      //cout<<len<<" is not valid length\n";
      retVal = 0;
    }
    return retVal;
}

int main()
{
  int a1[3] = {2,1,1};
  cout<<"{2,1,1}:"<<isMadhavArray(a1,3)<<"\n";

  int a2[6] = {2, 1, 1, 4, -1, -1}; 
  cout<<"{2, 1, 1, 4, -1, -1}:"<<isMadhavArray(a2,6)<<"\n";

  int a3[10] = {6, 2, 4, 2, 2, 2, 1, 5, 0, 0};
  cout<<"{6, 2, 4, 2, 2, 2, 1, 5, 0, 0}:"<<isMadhavArray(a3,10)<<"\n";

  int a4[6] = {18, 9, 10, 6, 6, 6};
  cout<<"{18, 9, 10, 6, 6, 6}:"<<isMadhavArray(a4,6)<<"\n";

  int a5[5] = {1,2,3,4,5};
  cout<<"{1,2,3,4,}: "<<isMadhavArray(a5,5)<<"\n";

  int a6[6] = {-6, -3, -3, 8, -5, -4};
  cout<<"{-6, -3, -3, 8, -5, -4}: "<<isMadhavArray(a6,6)<<"\n";

  int a7[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, -2, -1};
  cout<<"{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, -2, -1}:"<<isMadhavArray(a7,15)<<"\n";

  int a8[5] = {3, 1, 2, 3, 0};
  cout<<"{3, 1, 2, 3, 0}:"<<isMadhavArray(a8,5)<<"\n";
}

