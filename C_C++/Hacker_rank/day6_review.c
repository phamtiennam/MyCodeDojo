
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Given a string S , of length N that is indexed from 0 to N-1, print its even-indexed and odd-indexed characters as 2 space-separated strings on a single line (see the Sample below for more detail).
//
//Note: 0 is considered to be an even index.
//1<=T<=10
//2<=lengof(S)<=10000
//
//Sample Input
//
//  2
//  Hacker
//  Rank
//
//Sample Output
//
//  Hce akr
//  Rn ak
//
//Author: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_18

#include<stdio.h>
#include<string.h> 

int main(){
	int T,i,j,m,n;
	char strings[T][10000],odd[10000],even[10000];

	scanf("%d", &T); //the number of test cases.

	for(int i=0;i<T;i++){
		scanf(" %s", strings[i]);
	}
	for (i=0;i<T;i++){
		m = n = j = 0;
		odd[0]='\0';
		even[0]='\0';
		while(strings[i][j] != '\0'){
			if (j % 2 == 0){
				even[m++] = strings[i][j];
			}
			else {
				odd[n++] = strings[i][j];
			}
			j++;
		}
		even[m]='\0';
		odd[m]='\0';
		printf("%s  %s\n", even, odd);
	}	
	return 0;
}
