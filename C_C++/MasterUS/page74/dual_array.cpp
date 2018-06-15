/*
An  array  is  said  to  be  dual  if  it  has  an  even  number  of  elements 
and  each  pair  ofconsecutive  even  and  odd  elements  sum  to  the  same  value. 
Write  a  function  named  isDual  that  accepts  anarray  of  integers  
and  returns  1  if  the  array  is  dual,  otherwise  it  returns  0.  

Examples:    {1,  2,  3,  0}  is  a  dualarray  (because  1+2  =  3+0  =  3), 
{1,  2,  2,  1,  3,  0}  is  a  dual  array  (because  1+2  =  2+1  =  3+0  =  3),  
{1,  1,2,  2}</td>  is  not  a  dual  array  (because  1+1  is  not  equal  to  2+2), 
{1,  2,  1}</td>        <td>  is  not  a  dualarray  (because  array  does  not  have  an  even  number  of  elements),
{}  is  a  dual  array.

If  you  are  programming  in  Java  or  C#,  
the  function  signature  is    int  isDual(int[  ]  a)

If  you  are  programming  in  C  or  C++, 
the  function  signature  is   int  isDual(int  a[  ],  int  len)where  len  is  the  number  of  elements  in  the  array
*/
#include<iostream>
using namespace std;
int isDual(int a[],int len)
{
  int retVal = 0;
  if((len % 2 == 0) && (len > 2))
  {
    int index = len/2;
    int count = 0, sum = 0;
    int pre_sum = a[0] + a[1];
    
    for(int i=0;i<index;i++)
    {
      sum=a[count] + a[count+1];
      if((sum%2 != 0)&&(sum == pre_sum))
      {
        count += 2;
      }
      else
      {
        break;
      }
    }
    //cout<<"count:"<<count<<endl;
    if(count==len)
    {
      retVal = 1;
    }
  }
  else if(len == 2)
  {
    if((a[0]+a[1])%2 != 0)
    {
      retVal = 1;
    }
  }
  else if(len == 0)
  {
    retVal = 1;
  }
  return retVal;
}

int main()
{
  int a[4] = {1,  2,  3,  0};
  cout<<"a[4] = {1,  2,  3,  0}:"<<isDual(a,4)<<endl;
  
  int b[0] = {};
  cout<<"b[0] = {}:"<<isDual(a,0)<<endl;
  
  int c[6] = {1,  2,  2,  1,  3,  0};
  cout<<"c[6] = {1,  2,  2,  1,  3,  0}:"<<isDual(c,6)<<endl;
  
  int d[4] = {1,  1,2,  2};
  cout<<"d[4] = {1,  1,2,  2}:"<<isDual(d,4)<<endl;
  
  int e[3] = {1,  2,  1};
  cout<<"e[3] = {1,  2,  1}: "<<isDual(e,3)<<endl;
  
  return 0;
}