////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Complete the code in the editor below. The variables , , and  are already declared and initialized for you. You must:
//
//Declare  variables: one of type int, one of type double, and one of type String.
//Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your  variables.
//Use the  operator to perform the following operations: 
//Print the sum of  plus your int variable on a new line.
//Print the sum of  plus your double variable to a scale of one decimal place on a new line.
//Concatenate  with the string you read as input and print the result on a new line.
//
//---------------------------
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

int main() {
	int i=4,a;
	double d=4.0,b;
	char s[]="HackerRank ",c[1024*4];
	scanf("%d", &a);
	scanf("%lf", &b);
	//scanf("%[0-9a-zA-Z! ]s", c); //this code would'nt work with scanf in front.Have to add space 
	scanf(" %[0-9a-zA-Z! ]s", c); //Scanf the string with letters from 0-9a-zA-z,! and white space  
	printf("%d\n", i+a);
	printf("%.1lf\n", d+b);
	printf("%s%s\n", s, c);
	return 0;
}
