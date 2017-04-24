
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.
//
//We define the rating for Alice's challenge to be the triplet , and the rating for Bob's challenge to be the triplet .
//
//Your task is to find their comparison points by comparing a0 with b0,a1 with b1,and a2  with b2 .
//
//If ai > bi then Alice is awarded 1 point.
//If ai < bi then Bob is awarded 1 point.
//If ai = bi then neither person receives a point.
//Comparison points is the total points a person earned.
//
//Given  and , can you compare the two challenges and print their respective comparison points?
//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_04_15
#include <stdio.h>

int main(){
	int a[3],b[3],i,j,alice=0,bob=0;
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	scanf("%d %d %d", &b[0], &b[1], &b[2]);

	for (i=0 ; i<3 ; i++){
		if( a[i] > b[i] ){
			alice++;
		}
		else if(a[i] < b[i]) {
			bob++;
		}
	}
	printf("%d %d\n", alice, bob);
	return 0;
}
