#include<iostream>
using namespace std;

int isOlympic(int a[ ], int len)
{
    int retVal = 1;
    if (len < 2) retVal = 0;
    for (int i = 0; i < len; i++)
    {
        int sum = 0;
        for (int j = 0; j < len; j++)
        {
            if (a[j] < a[i]) sum += a[j];
        }
        if (a[i] < sum) retVal = 0;
    }
    return retVal;
}

int main()
{
  int a[3] = {3, 2, 1};
  cout<<isOlympic(a,3);
  
  int b[4] = {2, 2, 1, 1};
  cout<<isOlympic(b,4);
  
  int c[5] = {1, 1000, 100, 10000, 2};
  cout<<isOlympic(c,5);
  int d[5] = {1, 2, 1, 3, 2};
  cout<<isOlympic(d,5);
  
  int e[5] = {1, 2, -1, 2, 2};
  cout<<isOlympic(e,5);
  
}