/*
  An  array  is  called  balanced  if  its  even  numbered  elements  (a[0],  a[2],  etc.)
are  even  and its    odd  numbered  elements  (a[1],  a[3],  etc.)  are  odd.  

Write  a  functionnamed  isBalanced  that  accepts  an  array  of  integers  and  returns  1  
if  the  array  isbalanced,  otherwise  it  returns  0. 

Examples:    {2,  3,  6,  7}  is  balanced  
since  a[0]  and  a[2]are  even,
a[1]  and  a[3]  are  odd.  

{6,  7,  2,  3,  12}  is  balanced  since 
a[0],  a[2]  and  a[4]  areeven,  a[1]  and  
a[3]  are  odd. 

{7,  15,  2,  3}  is  not  balanced  since  a[0]  is  odd. 
{16,  6,  2,  3}is  not  balanced  since  a[1]  is  even.

If  you  are  programming  in  Java  or  C#,  the  function  signature  is    int  isBalanced(int[  ]  a)
If  you  are  programming  in  C  or  C++,  the  function  signature  is int  isBalanced(int  a[],int  len)
where  len  is  the  number  of  elements  in  the  array.    
*/

#include<iostream>
using namespace std;

int isBalanced(int a[],int len)
{
  int retVal = 0,count = 0;
  bool evenFlag = true;
  for(int i=0;i<len;i++)
  {
    if(evenFlag)
    {
     if (a[i]%2 == 0)
     {
       count++;
       evenFlag=false;
     }
     else
     {
       break;
     }
    }
    else
    {
      if(a[i]%2 != 0)
      {
        count++;
        evenFlag=true;
      }
      else
      {
        break;
      }
      
    }
  }
  if(count == len)
  {
    retVal = 1;
  }
  return retVal;
}

int main()
{
  int a[4] = {2,  3,  6,  7};
  cout<<"a[4] = {2,  3,  6,  7};"<<isBalanced(a,4)<<endl;
  
  int b[5] = {6,  7,  2,  3,  12};
  cout<<"b[4] = {6,  7,  2,  3,  12};"<<isBalanced(b,5)<<endl;
  
  int c[4] = {16,  6,  2,  3};
  cout<<"c[4] = {16,  6,  2,  3};"<<isBalanced(c,4)<<endl;
  
  return 0;
}