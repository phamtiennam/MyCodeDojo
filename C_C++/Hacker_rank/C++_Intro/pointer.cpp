
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:
/*
 You have to complete the function void update(int *a,int *b), which reads two integers as argument, and sets with the sum of them, and  with the absolute difference of them.

a'= a+b
b'=|a-b|

Input Format

 Input will contain two integers,a  and b , separated by a newline.

Output Format

 You have to print the updated value of a and b , on two different lines.
 
 
 */
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_05_30
#include <stdio.h>

void update(int *a,int *b) {
	int add,sub;
	add = *a + *b;
	sub = *a - *b;
	if(sub < 0){
		sub=-sub;
	}
	*a = add;
	*b = sub;
}

int main() {
	int a, b;
	int *pa = &a, *pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}

