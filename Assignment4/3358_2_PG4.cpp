// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 03/08/2017
// Programming Assignment 4
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Builds a sorted linked list

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

class NumberList
{
    private:
    struct ListNode
    {
        int data;
        struct ListNode *next;
    };

    ListNode *head;

    public:
    NumberList()
    {head = NULL;}

    ~NumberList();

    //void sort();   // why you output random number
    void appendNode(int);
    void insertNode(int);
    void deleteNode(int);
    void display() const;
    //bool search(int);
};

int main()
{
    NumberList list;

    list.appendNode(9);
    list.appendNode(7);
    list.appendNode(30);

    list.insertNode(-100);
    list.display();

    return 0;
}

NumberList::~NumberList()
{
   ListNode *p;
   ListNode *next;

   p = head;

   while (p!=NULL){

    next = p->next;

    delete p;
    p = next;
   }
}

/*void NumberList:: sort() // not sure this even works, junk prints out :/
{
   ListNode *ptr = head; // point to head
   ListNode *n = NULL; // trailer, previous node
   ListNode *newNode = new ListNode; // create new node

   if(!head){
    head = newNode;
    newNode->next=NULL;
   }

   else{
    ptr = head;
    n = NULL;
   //ptr = head->next; // keep maybe?

   while(ptr!=NULL && ptr->data < ptr->data){
     n = ptr;
     ptr = ptr->next;
   }

   if (n == NULL){
    head = newNode;
    newNode->next = ptr;
   }

   else{
    n->next = newNode;
    newNode->next = ptr;
    }
   }

}
*/
void NumberList::appendNode(int num)
 {
 	ListNode *newNode; // point to new node
 	ListNode *nodePtr; // move through the list

 	//allocate new node and store num there
 	newNode = new ListNode;
 	newNode->data = num;
 	newNode->next = NULL;

 	//if not new node, make newNode 1st node
 	if (!head)
 	head = newNode;
 	else	// otherwise, insert newNode at end
 	{
 		//Initiliaze nodePtr to head of lsit
 		nodePtr = head;

 		//Find the last node in list
 		while (nodePtr->next)
 			nodePtr = nodePtr->next;

 		//insert NnewNode as the last node.
 		nodePtr->next = newNode;
 	}
 }

void NumberList:: insertNode(int num)
{
    ListNode *newNode;
    ListNode *p;
    ListNode *n;

    newNode = new ListNode;
    newNode->data = num;

    p = head;
    while (p && p->data < num){
        n = p;
        p = p->next;
    }

    if (p == head){
        head = newNode;
        newNode->next = p;
    }
    else{
        n->next = newNode;
        newNode->next = p;
    }
}

/*bool NumberList:: search(int num)
{
   ListNode *ptr = head;

   while (ptr !=NULL)
    {
     if (ptr->data==str)
     {
        return ptr;
     }
     ptr = ptr->next;
    }

    return NULL;
}
*/

void NumberList:: display() const
{
   ListNode *ptr = head;

    while(ptr){
    cout << ptr->data << " ";
    ptr = ptr->next;
    }
}
