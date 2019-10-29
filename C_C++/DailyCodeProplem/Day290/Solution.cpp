#include <iostream>

using namespace std;

int get_num_remaining(string *array,int len)
{
    int nR=0;
    int nB=0;
    int nG=0;
    
    for (int i=0;i<len;i++)
    {
        if(array[i] == "B")
            nB++;
        if(array[i] == "R")
            nR++;
        if(array[i] == "G")
            nG++;
    }

    //cout<<"nB:"<<nB<<endl;
    //cout<<"nR:"<<nR<<endl;
    //cout<<"nG:"<<nG<<endl;

    if ((nB == len)||(nR == len)||(nG == len))
        return len;

    if((nB%2 == nR%2)&&(nB%2 == nG%2))
        return 2;
    else
        return 1;
}

int main()
{
    string array[] = {"G","B","B","B","R","G","B","R","R"};
    int n = sizeof(array)/sizeof(array[0]);
    //cout<<n<<endl;
    cout<<get_num_remaining(array,n);
    return 0;
}
