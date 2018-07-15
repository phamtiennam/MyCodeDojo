An array is defined to be a 235 array if the number of elements divisible by 2 plus the number of elements divisible by 3 plus the number of elements divisible by 5 plus the number of elements not divisible by 2, 3, or 5 is equal to the number of elements of the array. Write a method named is123Array that returns 1 if its array argument is a 235 array, otherwise it returns 0.

If you are writing in Java or C#, the function signature is
int is235Array(int[ ] a)

If you are writing in C or C++, the function signature is
int is235Array(int a[ ], int len) where len is the length of a

Hint: remember that a number can be divisible by more than one number

Examples

In the following: <a, b, c, d> means that the array has a elements that are divisible by 2, b elements that are divisible by 3, c elements that are divisible by 5 and d elements that are not divisible by 2, 3, or 5.

if a is	return	reason
{2, 3, 5, 7, 11}	1	because one element is divisible by 2 (a[0]), one is divisible by 3 (a[1]), one is divisible by 5 (a[2]) and two are not divisible by 2, 3, or 5 (a[3] and a[4]). So we have <1, 1, 1, 2> and 1+1+1+2 == the number of elements in the array.
{2, 3, 6, 7, 11}	0	because two elements are divisible by 2 (a[0] and a[2]), two are divisible by 3 (a[1] and a[2]), none are divisible by 5 and two are not divisible by 2, 3, or 5 (a[3] and a[4]). So we have <2, 2, 0, 2> and 2 + 2 + 0 + 2 == 6 != the number of elements in the array.
{2, 3, 4, 5, 6, 7, 8, 9, 10}	0	because <5, 3, 2, 1> and 5 + 3 + 2 + 1 == 11 != the number of elements in the array.
{2, 4, 8, 16, 32}	1	because <5, 0, 0, 0> and 5 + 0 + 0 + 0 == 5 == the number of elements in the array.
{3, 9, 27, 7, 1, 1, 1, 1, 1}	1	because <0, 3, 0, 6> and 0 + 3 + 0 + 6 == 9 == the number of elements in the array.
{7, 11, 77, 49}	1	because <0, 0, 0, 4> and 0 + 0 + 0 + 4 == 4 == the number of elements in the array.
{2}	1	because <1, 0, 0, 0> and 1 + 0 + 0 + 0 == 1 == the number of elements in the array.
{}	1	because <0, 0, 0, 0> and 0 + 0 + 0 + 0 == 0 == the number of elements in the array.
{7, 2, 7, 2, 7, 2, 7, 2, 3, 7, 7}	1	because <4, 1, 0, 6> and 4 + 1 + 0 + 6 == 11 == the number of elements in the array.


Copy and paste your answer here and click the "Submit answer" button


 
You should see a confirmation popup after hitting the submit button above. 
 
2. Define the weighted sum of an array to be 2 * the sum of the even valued elements + 3 * the sum of the odd valued elements.

Write a method named computeWeightedSum that computes the weighted sum of its argument.

If you are programming in Java or C#, the function signature is
int computeWeightedSum(int[ ] a)

If you are programming in C or C++, the function signature is
int computeWeightedSum(int a[ ], int len) where len is the number of elements in the array a.

You may assume that the input parameter is not null and that it contains at least one element.

Your method must make only one pass through the array, i.e, there must be only one loop in your method!

Examples

a is	then function returns	reason
{1, 2, 3, 4, 5}	39	2 * (2+4) + 3 * (1+3+5) = 39
{1, 3, 5}	27	3*(1 + 3 + 5) = 27
{2, 4, 6}	24	2*(2 + 4 + 6) = 24
{1}	3	3*(1) = 3
{2}	2	2*(2) = 4
{0, 0, 0, 0, 0}	0	2 * (0+0+0+0+0) = 0

Copy and paste your answer here and click the "Submit answer" button


 
You should see a confirmation popup after hitting the submit button above. 
 
3. An Olympic array is defined to be an array in which every value is greater than or equal to the sum of the values less than it. The sum of the values less than the minimum value in the array is defined to be 0.

For example, {3, 2, 1} is an Olympic array because

1 is the minimum value and by definition the sum of the values less than it is 0. Since 1 is greater than 0, it satisfies the condition.
There is only one value less than 2 and 2 is greater than it, so the value 2 satisfies the condition.
The values 1 and 2 are less than 3 and 3 is equal to their sum, so the value 3 satisfies the condition.
Hence all elements of the array satisfy the conditions and the array is an Olympic array.

{2, 2, 1, 1} is also an Olympic array because the values less than 2 sum to 2.

{1, 1000, 100, 10000, 2} is also an Olympic array. However, {1, 99, 99, 1000, 100, 10000, 2} is not an Olympic array because the sum of the numbers less than 100 (99+99+1) is greater than 100. Please be sure that your function detects that this is not an Olympic array!

{1, 2, 1, 3, 2} is not an Olympic array because 3 is not greater than or equal to 1+2+1+2.

{1, 2, -1, 2, 2} is not an Olympic array because -1 is the minimum value but it is not greater than or equal to 0.

Write a function named isOlympic that returns 1 if its array argument is an Olympic array, otherwise it returns 0.

If you are writing in Java or C#, the function signature is
   int isOlympic (int[ ] a)

If you are writing in C or C++, the function signature is
   int isOlympic(int a[ ], int len) where len is the number of elements in the array.

Hint: use a nested loop.

Copy and paste your answer here and click the "Submit answer" button


 
You should see a confirmation popup after hitting the submit button above. 

If you have submitted all three answers individually, you can click complete test button below. 
Before you press complete test button, make sure that you have submitted all three answers individually and received a confirmation popup saying your answers for that question was successfully submitted.
Once you click the complete test button, you can not modify or update your answers.
