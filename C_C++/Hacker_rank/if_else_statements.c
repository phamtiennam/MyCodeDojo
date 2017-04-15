
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:30 days of coding.Hackerrank.com
//Given an integer, , perform the following conditional actions:
//
//If  is odd, print Weird
//If  is even and in the inclusive range of  to , print Not Weird
//If  is even and in the inclusive range of  to , print Weird
//If  is even and greater than , print Not Weird
//Complete the stub code provided in your editor to print whether or not  is weird.
//----------------------------
//Author: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_15

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if (n%2){
		printf("Weird");
	}
	else if(n>=2 & n<=5){
		printf("Not Weird");
	}
	else if(n>=6 & n<=20){
		printf("Weird");
	}
	else if(n>=20){
		printf("Not Weird");
	}
	return 0;
}
