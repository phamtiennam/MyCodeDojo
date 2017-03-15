#include<stdio.h>
//recursion
//15Mar2017

void printNos(unsigned int n)
{
 if(n > 0)
 {
   printNos(n-1);
   printf("%d ", n);
 }
}

int main()
{
 printNos(100);
}
