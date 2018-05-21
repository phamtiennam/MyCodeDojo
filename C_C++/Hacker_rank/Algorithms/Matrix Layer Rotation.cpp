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
#include <bits/stdc++.h>
using namespace std;



int load_MatrixCircle_2_array(vector<vector<int> > *a , int array[], int i , int j, int sub_column, int sub_row, bool direction)
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
    
    if(t1 < (sub_column - 1))
    {
      j++;
      t1++;
    }
    else if(t2 < (sub_row - 1))
    {
      i++;
      t2++;
    }
    else if(t3 < (sub_column - 1))
    {
      j--;
      t3++;
    }
    else if(t4 < (sub_row - 2))
    {
      i--;
      t4++;
    }
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

int rotateCube(vector<vector<int> > *a , int i , int j , int sub_column, int sub_row, int rotate)
{
  int len = (2*(sub_row + sub_column) - 4);
  int array[len];
  
  load_MatrixCircle_2_array(a,array,i,j,sub_column,sub_row,true);
  
  for(int m=0;m<rotate;m++)
  {
    shiftLeft(array,len);  
  }
  
  load_MatrixCircle_2_array(a,array,i,j,sub_column,sub_row,false);
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split_string(mnr_temp);

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  
    int emin = min(m,n)/2;
    vector<vector<int> > *p = &matrix;
    for(int b=0;b<emin;b++)
    {
      //rotateCube(vector<vector<int> > *a , int i , int j , int sub_row , int sub_column , int rotate)
      rotateCube(p,b,b,n,m,r);
      //cout<<"matrix[i][j]:"<<matrix[b][b]<<endl;
      //rotateCube(p,0,0,m,n,r);
      m=m-2;
      n=n-2;
    }
    
    for (int l = 0; l < matrix.size(); l++) {
        for (int d = 0; d < matrix[l].size(); d++)
            cout << matrix[l][d] << " ";
        cout << endl;
    }
    return 0;
}