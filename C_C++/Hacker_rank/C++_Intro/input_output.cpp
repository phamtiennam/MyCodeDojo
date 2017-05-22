
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Description:
/*
Task 
Read 3 numbers from stdin and print their sum to stdout.

Note: If you plan on completing this challenge in C instead of C++, you'll need to use format specifiers with printf and scanf.

Input Format

A single line containing 3 space-separated integers:a , b, and c.

Constraints
 1<= a,b,c <= 1000

Output Format

Print the sum of the three numbers on a single line.
*/

//Coder: NamPham
//Email: nampt282@gmail.com
//Date: 2017_05_22
#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << a+b+c << endl;
	return 0;
}
