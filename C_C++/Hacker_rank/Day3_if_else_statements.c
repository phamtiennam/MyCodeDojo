
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:30 days of coding.Hackerrank.com
//Given an integer,n , perform the following conditional actions:
//
//If n is odd, print Weird
//If n is even and in the inclusive range of 2 to 5, print Not Weird
//If n is even and in the inclusive range of 6 to 20, print Weird
//If n is even and greater than 20, print Not Weird
//Complete the stub code provided in your editor to print whether or not n is weird.
//----------------------------
//Coder: NamPham
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
