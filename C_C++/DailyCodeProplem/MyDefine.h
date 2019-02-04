#ifndef CLIST_H
#define CLIST_H

struct Node
{
	int data;
	Node *next;
};

class LinkedList{
	
public:
	//contructor
	LinkedList(){
		head = NULL;
	}
	//destructor
	~LinkedList()
	{}
	//add new node at the begining of the Linked List
	void addValue(int val){
		Node *n = new Node();
		n->data = val;
		n->next = head;
		head = n;

	}
	//remove the firt node of the Linked List
	int popValue(){
		Node * tmp=head;
		int reVal = tmp->data;
		head=head->next;
		delete tmp;
		return reVal;
	}
	//print value of LinkedList
	void printAll(){
		Node *prt = head;
		while(prt){
			std::cout<<prt->data<<std::endl;
			prt=prt->next;
		}
	}
public:
	Node *head ;
};

#endif //CLIST_H