/*
Problem:
You are given a 2D matrix of dimension m*n and a positive integer r .
You have to rotate the matrix r times and print the resultant matrix.
Rotation should be in anti-clockwise direction.
It is guaranteed that the minimum of m and n will be even.

Input Format:
The first line contains three space separated integers,m ,n , and r, the number of rows and columns in matrix, and the required rotation. 
The next m lines contain n space-separated integers representing the elements of a row of matrix.

Output Format:
Print each row of the rotated matrix as space-separated integers on separate lines.
*/

#include<iostream>
#include <vector>
using namespace std;

int load_MatrixCircle_2_array(vector<vector<int> > *a , int array[], int i , int j, int sub_row , int sub_column, bool direction)
{
  int len = (2*(sub_row + sub_column) - 4);
  
  int t1=0,t2=0,t3=0,t4=0;
  
  for(int k=0;k<len;k++)
  {
    if(direction)
    {
     /* Load*/
      array[k] = (*a)[i][j];
    }
    else
    {
      /*Off Load*/
      (*a)[i][j] = array[k];
    }
    
    if(t1 < sub_row)
    {
      j++;
      t1++;
    }
    else if(t2<sub_column)
    {
      i++;
      t2++;
    }
    else if()
  }
  return 0;
}
int shiftLeft(int a[],int len)
{
  int tmp = a[0];
  for(int i=0;i < (len-1);i++)
  {
    a[i] = a[i+1];
  }
  a[len-1] = tmp;
  return 0;
}

int rotateCube(vector<vector<int> > *a , int i , int j , int sub_row , int sub_column , int rotate)
{
  int array[len];
  
}

int main()
{
  /*
    vector<vector<int> > vect = { {1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
  vector<vector<int> > *p = &vect;
  
  rotateCube(p,0,0,1,1,0);
  for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
  */
  /*Test shiftLeft
  int a[4] = {0,1,2,3};
  shiftLeft(a,4);
  cout<<"a[0]:"<<a[0]<<endl;
  shiftLeft(a,4);
  cout<<"a[0]:"<<a[0]<<endl;
  shiftLeft(a,4);
  cout<<"a[0]:"<<a[0]<<endl;
  shiftLeft(a,4);
  cout<<"a[0]:"<<a[0]<<endl;
  shiftLeft(a,4);
  cout<<"a[0]:"<<a[0]<<endl;
  */
  
  return 0;
  
}