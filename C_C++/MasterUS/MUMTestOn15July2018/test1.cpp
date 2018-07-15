#include<iostream>
using namespace std;
int is235(int a[],int len)
{
  int retVal = 0;
  int div2 = 0,div3 = 0,div5 = 0,divNot = 0,sum = 0;
  for(int i=0;i<len;i++)
  {
    if(a[i]%2 == 0)
    {
      div2++;
    }
    if(a[i]%3 == 0)
    {
      div3++;
    }
    if(a[i]%5 == 0)
    {
      div5++;
    }
    if((a[i]%2 != 0)&&(a[i]%3 != 0)&&(a[i]%5 != 0))
    {
      divNot++;
    }
  }
  sum = divNot + div5 + div3 + div2;
  if(sum == len)
  {
    retVal = 1;
  }
  return retVal;
}

int main()
{
  int a1[5]={2, 3, 5, 7, 11};
  cout<<is235(a1,5)<<endl;
  
  int a2[5]={2, 3, 6, 7, 11};
  cout<<is235(a2,5)<<endl;
  
  int a3[9]={2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout<<is235(a3,9)<<endl;
  
  int a[5]={2, 4, 8, 16, 32};
  cout<<is235(a,5)<<endl;
  
  int a4[9]={3, 9, 27, 7, 1, 1, 1, 1, 1};
  cout<<is235(a4,9)<<endl;
  
  int c[4] = {7, 11, 77, 49};
  cout<<is235(c,4)<<endl;
  
  int a5[1]= {2};
  cout<<is235(a5,1)<<endl;
  
  int a6[] = {};
  cout<<is235(a6,0)<<endl;
  
  int b[11] = {7, 2, 7, 2, 7, 2, 7, 2, 3, 7, 7};
  cout<<is235(b,11)<<endl;
  
  
  return 0;
}