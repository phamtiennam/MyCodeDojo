/*
*___________________________Description____________________________________________
 An array is defined to be inertial if the following conditions hold:
 a. it contains at least one odd value
 b. the maximum value in the array is even
 c. every odd value is greater than every even value that is not the maximum value. 
So {11, 4, 20, 9, 2, 8} is inertial because 
 a. it contains at least one odd value
 b. the maximum value in the array is 20 which is even
 c. the two odd values (11 and 9) are greater than all the      
    even values that are not equal to 20 (the maximum), i.e., (4, 2, 8}. 
However, {12, 11, 4, 9, 2, 3, 10} is not inertial because it fails condition (c), i.e., 10 (which is 
even) is greater 9 (which is odd) but 10 is not the maximum value in the array.
Write a function called 
isIntertial
 that accepts an integer array and returns 1 if the array is 
inertial; otherwise it returns 0. 
If you are programming in Java or C#, the function signature is 
int isInertial(int[ ] a) 
If you are programming in C or C++, the function signature is 
int isInertial(int a[ ], int len) where len is the number of elements in the array 
*/

#include<iostream>
#include <algorithm> 

using namespace std;

int isInertial(int a[], int len)
{
	int retVal = 1;
	if(len >= 2)
	{
		/*Sort the input array*/
		sort(a,a+len);
		cout << "\nArray after sorting: ";
    	for (int i = 0; i < len; ++i)
    	{
    		cout <<a[i]<<" ";
    	}
    	/*Check if the maximum element is even and the privious element in sorted array is odd*/
    	if( ((a[len-1] % 2) == 0) &&((a[len-2] % 2) != 0))  
    	{
    		if(len >= 3)
    		{
    			for(int i=len-3;i>=0;i--)
    			{
    				if((a[i]%2 == 0) &&(a[i-1]%2 != 0 ))
    				{
    					// there is a Even value is greter then Odd value
    					break;
    					retVal = 0;
    				    cout<<"\nThis is NOT an inertial array\n";	
    				}
    			}
    		}
    	}
    	else
    	{
    		cout<<"Condition not met for inertial array";
    		retVal = 0;
    	}
	}
	else
	{
		cout<<len<<" is not valid Length for an inertial array\n";
		retVal = 0;
	}
	cout<<"\n";
	return retVal;
}

int main()
{
	int a[1] = {1};
	cout<<isInertial(a,1)<<endl;

int a2[1] = {2};
	cout<<isInertial(a2,1)<<endl;

int a3[4] = {1,2,3,4};
	cout<<isInertial(a3,4)<<endl;

int a4[7] = {1,1,1,1,1,1,2};
	cout<<isInertial(a4,7)<<endl;

int a5[6] = {2,12,4,6,8,11};
	cout<<isInertial(a5,6)<<endl;

int a6[7] = {2,12,12,4,6,8,11};
	cout<<isInertial(a6,7)<<endl;

int a7[5] = {-2,-4,-6,-8,-11};
	cout<<isInertial(a7,5)<<endl;

int a8[4] = {2,3,4,7};
	cout<<isInertial(a8,4)<<endl;

int a9[5] = {2,4,6,8,10};
	cout<<isInertial(a9,5)<<endl;


	return 0;
}