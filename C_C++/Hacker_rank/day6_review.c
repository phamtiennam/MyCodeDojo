
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
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_18

#include<stdio.h>
#include<string.h> 

int main(){
	int T,i,j,length;
	char strings[10000];

	scanf("%d", &T); //the number of test cases.

	for(int i=0;i<T;i++){
		length=0;
		scanf(" %[^\n]", strings);
		length=strlen(strings);
		for(j=0;j<length;j++){
			if(j % 2 == 0){
				printf("%c", strings[j]);
			}
		}	
		printf(" ");
		for(j=0;j<length;j++){
			if(j % 2 != 0){
				printf("%c", strings[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
