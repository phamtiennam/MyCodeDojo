
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Given an integer,n , print its first 10 multiples. Each multiple n*i  (where 1<= i <= 10 ) should be printed on a new line in the form: n x i = result.
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_16
#include <stdio.h>

int main(){
	int i=1,n;
	scanf("%d", &n);
	while(i<=10){
		printf("%d x %d = %d\n", n, i, n*i);
		i++;
	}
	return 0;
}
