// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 03/29/2017
// Programming Assignment 5
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// A program that implements a Stack and Queue ADT with Templates.

#include <iostream>
#include <cassert>
#include <limits>
#include <conio.h>

using namespace std;

template <class T> class Stack_Queue{
private:
    int sSize;
    int qSize;
    int top;
    int front;
    int rear;
    T *queue;
    T *stack;
    T *resizeStack();
    T *resizeQueue();
public:
    Stack_Queue();
    ~Stack_Queue();
    void push(T);
    T pop();
    void enqueue(T);
    T dequeue();
    bool isStackEmpty();
    bool isQueueEmpty();
    int stackLength();
    int queueLength();
};

//=================================== Main =====================================
int main(){


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
    string expressionS;
    string expressionQ;

    do {

        cout << "Select from the following menu" << endl
             << "1.   Enter Stack / Queue Values" << endl
             << "9.   Terminate the program" << endl;

        try {

            cout << "Enter your choice";
            choice = getch();
            cout << endl;

            if (choice < '0' || choice > '9') {
                throw "That is not a number!";
            }
            else if (choice != '1' && choice != '9') {
                throw "That is not a valid menu option!";
            }

//==============================================================================
//                                 Part 1
//==============================================================================

            if (choice == '1'){

                Stack_Queue<char> characters;

                cout << endl;
                cout << "Enter Stack Values terminated by \';\'|   ";
                getline(cin, expressionS, ';');
                cout << endl;
                cout << "Enter Queue Values terminated by \';\'|   ";
                getline(cin, expressionQ, ';');

                for (int i = 0; i < expressionS.length(); i++){
                    characters.push(expressionS[i]);
                }
                for (int i = 0; i < expressionQ.length(); i++){
                    characters.enqueue(expressionQ[i]);
                }

                int qLen = characters.queueLength();

                char *arr = new char[qLen];
                for (int i = characters.queueLength() - 1; i >= 0; i--){
                    arr[i] = characters.dequeue();
                }

                bool same = true;
                for (int i = 0; i < characters.stackLength(); i++){
                    if(characters.pop() != arr[i]){
                        same = false;
                    }
                }

                cout << endl;
                if (same){
                    cout << "Stack and Queue are identical" << endl << endl;
                }
                else {
                    cout << "Stack and Queue are not identical" << endl << endl;
                }

//==============================================================================
//                                 Part 2
//==============================================================================
                Stack_Queue<char> grouping;

                for (int i = 0; i < expressionS.length(); i++){
                    characters.push(expressionS[i]);
                }

                char ch;
                bool group = false;

                while (!(characters.isStackEmpty())){
                    ch = characters.pop();

                    if (ch == ')' || ch == ']' || ch == '}'){
                        switch (ch){
                        case ')':
                            grouping.push('(');
                            break;
                        case ']':
                            grouping.push('[');
                            break;
                        case '}':
                            grouping.push('{');
                            break;
                        default:
                            break;
                        }
                    }

                    if (ch == '(' || ch == '[' || ch == '{'){

                        if(!grouping.isStackEmpty()){
                            char popChar = grouping.pop();

                            // Unexpected character condition
                            if (popChar != ch){
                                group = true;
                            }

                        }
                        // Unmatched closing bracket condition
                        else {
                            group = true;
                        }
                    }
                }

                // Missing condition
                if (!grouping.isStackEmpty()){
                    group = true;
                }

                if (!group){
                    cout << "First Expression has matching grouping symbols."
                         << endl << endl;
                }
                else {
                    cout << "First Expression does not have matching grouping"
                         << " symbols." << endl << endl;
                }
            }

        }
        catch (const char* error) {
            cerr << "\nERROR: " << error << "\n"
                 << "Please choose a valid option." << endl;
        }
        cout << endl;

    } while (choice != '9');

    cout << "*** Program is terminated. Written by Rafael Reza "
         << "& Cullen Sturdivant ***" << endl;

    return 0;
}
//==============================================================================

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> Stack_Queue<T>::Stack_Queue(){
    sSize = 1;
    qSize = 1;
    top = 0;
    front = 0;
    rear = front;
    stack = new T[sSize];
    queue = new T[qSize];
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> Stack_Queue<T>::~Stack_Queue(){
    delete [] stack;
    delete [] queue;
    stack = NULL;
    queue = NULL;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> void Stack_Queue<T>::push(T data){
    if (top == sSize){
        resizeStack();
    }

    stack[top] = data;
    top++;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> T Stack_Queue<T>::pop(){
    if (isStackEmpty()){
        cerr << "ERROR: Stack Underflow!" << endl;
        assert (false);
    }
    T temp = stack[top - 1];
    top--;
    return temp;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> void Stack_Queue<T>::enqueue(T data){
    if (((rear + 1) % qSize) == front){
        resizeQueue();
    }

    queue[rear] = data;
    rear = (rear + 1) % qSize;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> T Stack_Queue<T>::dequeue(){
    if (isQueueEmpty()){
        cerr << "ERROR: Stack Underflow!" << endl;
        assert (false);
    }

    T temp = queue[front];
    front = (front + 1) % qSize;
    return temp;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> bool Stack_Queue<T>::isStackEmpty(){
    if(top == 0){
        return true;
    }
    return false;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> bool Stack_Queue<T>::isQueueEmpty(){
    if (rear == front){
        return true;
    }
    return false;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> T *Stack_Queue<T>::resizeStack(){

    T *newStack;
    sSize *= 2;
    newStack = new T[sSize];

    for (int i = 0; i < sSize; i++)
        newStack[i] = stack[i];

    delete [] stack;
    stack = newStack;

    return stack;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> T *Stack_Queue<T>::resizeQueue(){

    T *newQueue;
    qSize *= 2;
    newQueue = new T[qSize];

    for (int i = 0; i < qSize; i++)
        newQueue[i] = queue[i];

    delete [] queue;
    queue = newQueue;

    return queue;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> int Stack_Queue<T>::stackLength(){
    return top;
}

//==============================================================================
// [Description]
//
// [Params]
//
// [Returns]
//==============================================================================
template <class T> int Stack_Queue<T>::queueLength(){
    int count = 0;
    int i = front;
    do{
        if (i == (qSize - 1)){
            i = 0;
        }
        else {
            i++;
        }
        count++;
    } while (i != rear);

    return count;
}
