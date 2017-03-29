// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 03/29/2017
// Programming Assignment 5
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// WE REALLY CAN'T FORGET TO EDIT THIS THIS TIME FO REAL FO REAL

#include <iostream>
#include <limits>

using namespace std;

template<class stackType> class Stack{

private:
    struct ListNode
    {
        stackType data;
        ListNode *next;
    };

    ListNode *head;

public:
    Stack();
    ~Stack();

    void push(stackType);
    stackType pop();
    int length();
    bool isEmpty() const;
};

template<class queueType> class Queue{

private:
    struct ListNode
    {
        queueType data;
        ListNode *next;
    };

    ListNode *head;

public:
    Queue();
    ~Queue();

    void enqueue(queueType);
    queueType dequeue();
    int length();
    bool isEmpty() const;
};


int main(){

    Stack<char> stack1;
    Queue<char> queue1;

    cout << "==== Welcome to My Stack / Queue Program ====" << endl << endl;
    cout << "The function of this program is to: " << endl << endl;

    cout << "\t1.\tValidate that a stack and a" << endl
         << "\t\tqueue are identical." << endl
         << "\t\tStacks / queues are the same if" << endl
         << "\t\tthey have the same number of elements, symbols," << endl
         << "\t\tand their elements and symbols at the" << endl
         << "\t\tcorresponding positions are the same." << endl << endl;

    cout << "\t2.\tThe Program also outputs whether the elements" << endl
         << "\t\tdo have the same matching group symbols." << endl <<  endl;

    int choice;
    string expression1;
    string expression2;

    do {

        cout << "Select from the following menu" << endl
             << "1.   Enter Stack / Queue Values" << endl
             << "9.   Terminate the program" << endl;

        try {

            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
                throw "That is not a number!";
            }
            else if (choice != 1 && choice != 9) {
                throw "That is not a valid menu option!";
            }

//==============================================================================
            if (choice == 1){
                cout << endl;
                cout << "Enter Stack Values terminated by a \';\'   :";
                getline(cin, expression1, ';');
                string temp1 = expression1;
                for (int i = 0; i < expression1.length(); i++){
                    //stack1.push(expression1[i]);
cout << "expression1: " << expression1[i] << endl;
                }

                cout << "Enter Queue Values terminated by a \';\'   :";
                cin >> ws;
                getline(cin, expression2, ';');
                string temp2 = expression2;
                for (int i = 0; i < expression2.length(); i++){
                    queue1.enqueue(expression2[i]);
cout << "expression2 " << expression2[i] << endl;
                }
cout << "stack1: " << stack1.pop();
/*
                if (stack1.length() != queue1.length()){
                    cout << "Stack and Queue are not identical" << endl << endl;
                }
                else {
                    bool flag = true;
                    char stk[stack1.length()];
                    char que[queue1.length()];
                    for (int i = stack1.length() - 1; i >= 0; i--){
                        stk[i] = stack1.pop();
                    }
                    for (int i = 0; i < queue1.length(); i++){
                        que[i] = queue1.dequeue();
                    }
                    for (int i = 0; i < stack1.length(); i++){
                        if (stk[i] != que[i]){
                            flag = false;
                        }
                    }
                    if (flag){
                        cout << "Stack and Queue are identical" << endl << endl;
                    }
                    else {
                        cout << "Stack and Queue are not identical\n" << endl;
                    }
                }
*/
            }
//==============================================================================
        }
        catch (const char* error) {
            cerr << "\nERROR: " << error << "\n"
                 << "Please choose a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;

    } while (choice != 9);

    cout << "*** Program is terminated. Written by Rafael Reza "
         << "& Cullen Sturdivant ***" << endl;

    return 0;
}

//==============================================================================
// Stack functions
//==============================================================================
template<class stackType> Stack<stackType>::Stack(){
    head = NULL;
}

template<class stackType> Stack<stackType>::~Stack(){
    ListNode *p = head;

    while (head){
        head = head->next;

        delete p;
        p = head;
    }
}

template<class stackType> void Stack<stackType>::push(stackType value){
    ListNode *newNode;
 	ListNode *nodePtr;

 	newNode = new ListNode;
 	newNode->data = value;
 	newNode->next = NULL;

 	if (!head){
        head = newNode;
 	}
 	else
 	{

 		nodePtr = head;


 		while (nodePtr->next)
 			nodePtr = nodePtr->next;

 		nodePtr->next = newNode;
 	}
}

template<class stackType> stackType Stack<stackType>::pop(){
    ListNode *p = head;
    ListNode *n;

    for(int i = 0; i < length(); i++){
        n = p;
        p = p->next;
    }
    n->next = n->next->next;
    stackType temp = p->data;
    delete p;
    return temp;
}

template<class stackType> bool Stack<stackType>::isEmpty() const{
    if (length() == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class stackType> int Stack<stackType>::length(){
    ListNode *p = head;
    int count = 0;

    while(p){
        p = p->next;
        count++;
    }
    return count;
}
//==============================================================================
//==============================================================================

//==============================================================================
// Queue functions
//==============================================================================
template<class queueType> Queue<queueType>::Queue(){
    head = NULL;
}

template<class queueType> Queue<queueType>::~Queue(){
    ListNode *p = head;

    while (head){
        head = head->next;

        delete p;
        p = head;
    }
}

template<class queueType> void Queue<queueType>::enqueue(queueType value){
    ListNode *newNode;
 	ListNode *nodePtr;

 	newNode = new ListNode;
 	newNode->data = value;
 	newNode->next = NULL;

 	if (!head)
 	head = newNode;
 	else
 	{

 		nodePtr = head;


 		while (nodePtr->next)
 			nodePtr = nodePtr->next;

 		nodePtr->next = newNode;
 	}
}

template<class queueType> queueType Queue<queueType>::dequeue(){
    ListNode *p = head;

    head = head->next;
    queueType temp = p->data;
    delete p;
    return temp;
}

template<class queueType> bool Queue<queueType>::isEmpty() const{
    if (length() == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class queueType> int Queue<queueType>::length(){
    ListNode *p = head;
    int count = 0;

    while(p){
        p = p->next;
        count++;
    }
    return count;
}
