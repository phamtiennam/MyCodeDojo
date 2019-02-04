/*
This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

#include <iostream>
#include "MyDefine.h"

using namespace std;
void removeElementFromList(LinkedList list,int k)
{
    Node *fast;
    Node *slow;
    fast=list.head;
    slow=list.head;

    //move pointer *fast to the k position first

    while(k>0)
    {
        fast=fast->next;
        --k;
    }

    //now move pointer *slow and *fast to gether,
    // *fast will reach the end of list
    // *slow will reach the N-k postion.N is lengh of list
    // *pre save the previous position of *slow

    Node *pre;

    while(fast)
    {
        fast=fast->next;
        pre=slow;
        slow=slow->next;    
    }
    //Now *slow point to the K position.Remove it
    pre->next=slow->next;
    list.printAll();
}

int main(int argc, char const *argv[])
{
    /* code */
    int k=3;
    LinkedList list;
    list.addValue(1);
    list.addValue(2);
    list.addValue(3);
    list.addValue(4);
    list.addValue(5);
    list.addValue(6);
    list.printAll();
    cout<<"Remove the last "<<k<<"th element in LinkedList"<<endl;
    removeElementFromList(list,k);
    
    return 0;
}