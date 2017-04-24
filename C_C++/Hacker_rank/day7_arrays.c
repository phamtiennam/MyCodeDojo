
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Given an array,A, of N integers, print A's elements in reverse order as a single line of space-separated numbers.
/*
-->Input Format
The first line contains an integer, N (the size of our array). 
The second line contains N space-separated integers describing array 's elements.
-->Output Format

Print the elements of array  in reverse order as a single line of space-separated numbers.

*/
//Author: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_23
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,lengh=0;
	scanf("%d", &n);
	int *arr = malloc(sizeof(int) * n);

	for(int arr_i=0;arr_i<n;arr_i++){
		scanf("%d",&arr[arr_i]);
		lengh++;
	}
	for(int j=lengh-1;j>=0;j--){
		printf("%d ", arr[j]);
	}

	return 0;
}
