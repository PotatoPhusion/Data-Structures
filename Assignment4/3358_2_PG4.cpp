// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 03/08/2017
// Programming Assignment 4
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Builds and manipulates linked lists.

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <limits>

using namespace std;

class NumberList {

private:
    struct ListNode
    {
        int data;
        ListNode *next;
    };

    ListNode *head;

public:
    // Constructor
    NumberList()
    {head = NULL;}

    // Destructor
    ~NumberList();

    int findMinimum();
    int getData(int);
    int search(int);
    int length();
    bool deleteData(int);
    NumberList listUnion(NumberList);
    NumberList listIntersection(NumberList);
    NumberList deleteDupes();
    void sortList();
    void appendNode(int);
    void clear();
    void insertNode(int, int);
    void deleteNode(int);
    void display() const;
    void displayBack() const;
    void rotateList(int);
    void splitList(NumberList&, NumberList&);
};

int main() {
    char choice;

    cout << "Welcome to Reza's and Sturdivant's Linked List Manipulation "
         << "Program." << endl << endl;

    do{
        NumberList numList;

//================================= Part A =====================================
        cout << "A sorted list of 19 random integer numbers that are between"
             << " 10 and 20 are as follows: " << endl << endl;

        srand(time(0));

        for (int i = 0; i < 19; i++){
            numList.appendNode(rand() % 11 + 10);
        }

        numList.sortList();
        numList.display();
        cout << endl;


//================================= Part B =====================================
        cout << "Main list after inserting new number -100 at the beginning:"
             << endl << endl;

        numList.insertNode(0, -100);
        numList.display();

        cout << endl;

//================================= Part C =====================================
        cout << "Main list after inserting new number 15 at the third location:"
             << endl << endl;

        numList.insertNode(2, 15);
        numList.display();

        cout << endl;

//================================= Part D =====================================
        cout << "Main list after appending new number 1000:" << endl << endl;

        numList.appendNode(1000);
        numList.display();

        cout << endl;

//================================= Part E =====================================
        cout << "Main list after removing number 5:" << endl << endl;

        if (!numList.deleteData(5))
            cout << "Item not found!" << endl;
        numList.display();

        cout << endl;

//================================= Part F =====================================
        cout << "Main list after removing the second element:" << endl << endl;

        numList.deleteNode(1);
        numList.display();

        cout << endl;

//================================= Part G =====================================
        cout << "Main list after rotating the list one position to the right:"
             << endl << endl;

        numList.rotateList(1);
        numList.display();

        cout << endl;

//================================= Part H =====================================
        cout << "Searching the main list for item number 17:" << endl << endl;

        try {
            int index = 0;
            index = numList.search(17);
            if (index >= 0){
                cout << "Item found at location " << index << endl;
            }
            else{
                cout << "Item not found" << endl;
            }
        }
        catch (const char* error){
            cerr << error << endl;
        }

        cout << endl;

//================================= Part I =====================================
        cout << "Displaying the main list backward:" << endl << endl;

        numList.displayBack();

        cout << endl;

//================================= Part J =====================================
        NumberList sub_List_1;
        NumberList sub_List_2;

        cout << "Splitting the main list into 2 sub lists (sub_List_1 and "
             << "sub_List_2)." << endl << endl;

        numList.splitList(sub_List_1, sub_List_2);

        cout << "Main List:" << endl << endl;
        numList.display();
        cout << endl;

        cout << "sub_List_1:" << endl << endl;
        sub_List_1.display();
        cout << endl;

        cout << "sub_List_2:" << endl << endl;
        sub_List_2.display();
        cout << endl;

        cout << "The union of the two sub lists is as follows:" << endl << endl;
        NumberList unionList;
        unionList = sub_List_1.listUnion(sub_List_2);
        unionList.display();
        cout << endl;


        cout << "The intersection of the two sub lists is as follows:\n\n";
        NumberList intersection;
        intersection = sub_List_1.listIntersection(sub_List_2);
        intersection.display();
        cout << endl;


//================================= Part K =====================================
        cout << "Main list after deleting duplicate numbers:" << endl << endl;
        numList = numList.deleteDupes();
        numList.display();
        cout << endl;


//================================= Part L =====================================
        cout << "Deleting the main list:" << endl << endl;
        numList.clear();
        numList.display();
        cout << endl;


//================================= Part X =====================================
        cout << "Searching the main list for item number 35:" << endl << endl;

        try {
            int index = 0;
            index = numList.search(35);
            if (index >= 0){
                cout << "Item found at location " << index << endl;
            }
            else{
                cout << "Item not found" << endl;
            }
        }
        catch (const char* error){
            cerr << error << endl;
        }

        cout << endl;


        cout << "Would you like to re-run the program?" << endl
             << "Enter Y or N..........: ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        // Catches bad inputs
		while(choice != 'Y' && choice != 'N' || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error! Invalid choice " << choice << " - Must enter Y or N"
                 << endl << endl;
            cout << "Would you like to re-run the program?" << endl
                 << "Enter Y or N..........: ";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;
		}
    }while (choice != 'N');

    cout << "This Linked List program is implemented by Rafael Reza "
         << "& Cullen Sturdivant" << endl << "March - 2017" << endl;

    return 0;
}

//******************************************************************************
// Deletes all elements of a linked list when it is unloaded from memory.
//******************************************************************************
NumberList::~NumberList(){
    ListNode *p = head;

    while (head){
        head = head->next;

        delete p;
        p = head;
    }
}

//******************************************************************************
// Finds the lowest value in a linked list of integers.
//
// Returns: int - The lowest value in the linked list
//******************************************************************************
int NumberList::findMinimum(){

	ListNode *p = head->next;
	int min = head->data;

	while (p){
		if (p->data < min){
			min = p->data;
		}
		p = p->next;
	}
	return min;
}

//******************************************************************************
// Sorts a linked list.
//******************************************************************************
void NumberList::sortList(){

	ListNode *newNumberList = NULL;
	ListNode *n = newNumberList;
	int nodeData;

	while (head){
		nodeData = findMinimum();

		ListNode *newNode = new ListNode;

		newNode->data = nodeData;
		newNode->next = NULL;

		deleteData(nodeData);

		if (newNumberList == NULL){
			newNumberList = newNode;
			n = newNode;
		}
		else
			n->next = newNode;

		n = newNode;
	}
	head = newNumberList;
}

//******************************************************************************
// Appends a node to the end of a linked list.
//
// int num: the number to be placed in the data segment of the node
//******************************************************************************
void NumberList::appendNode(int num) {

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
 		//Initialize nodePtr to head of list
 		nodePtr = head;

 		//Find the last node in list
 		while (nodePtr->next)
 			nodePtr = nodePtr->next;

 		//insert newNode as the last node.
 		nodePtr->next = newNode;
 	}
}

//******************************************************************************
// Inserts a node anywhere in a linked list.
//
// int location: what element in the list to place the node at
// int num: the value to be stored in the data portion of the node
//******************************************************************************
void NumberList::insertNode(int location, int num) {

    assert(location >= 0);

    ListNode *newNode = new ListNode;
    ListNode *p;
    ListNode *n;

    newNode->data = num;
    p = head;

    if(location == 0){
        newNode->next = head;
        head = newNode;
    }
    else{
        for (int i = 0; p && i < location; i++){
            n = p;
            p = p->next;
        }
        newNode->next = p;
        n->next = newNode;
    }
}

//******************************************************************************
// Gets the data element form a linked list node in a linked list.
//
// int location: the index of the node to retrieve the data from.
//
// Returns: int - the data returned from the node.
//******************************************************************************
int NumberList::getData(int location){
    ListNode *p = head;

    for (int i = 0; i < location; i++){
        p = p->next;
    }
    return p->data;
}

//******************************************************************************
// Deletes a node in a linked list based on the value in its data segment.
//
// int nodeData: the value to search for in the list
//
// Returns: bool - if the node was successfully deleted or not
//******************************************************************************
bool NumberList::deleteData(int nodeData){

    ListNode *p = head;
    ListNode *n;

    // While p does not point to NULL
    while (p){
        if (p->data == nodeData){
            if (p == head){
                head = p->next;
                delete p;
                return true;
            }
            n->next = p->next;
            delete p;
            return true;
        }
        n = p;
        p = p->next;
    }
    return false;
}

//******************************************************************************
// Joins two lists together by distinct elements only.
//
// NumberList list2: the list to be unionized with
//
// Returns: NumberList - the new union of two lists
//******************************************************************************
NumberList NumberList::listUnion(NumberList list2){
    NumberList unionList;
    ListNode *p = head;

    unionList.appendNode(p->data);

    while(p){
        if (!(unionList.search(p->data) >= 0)){
            unionList.appendNode(p->data);
        }
        p = p->next;
    }
    for(int i = 0; i < list2.length(); i++){
        if (!(unionList.search(list2.getData(i)) >= 0)){
            unionList.appendNode(list2.getData(i));
        }
    }
    return unionList;
}

//******************************************************************************
// Joins two lists together by common elements only.
//
// NumberList list2: the list to be intersected with
//
// Returns: NumberList - the new intersection of two lists
//******************************************************************************
NumberList NumberList::listIntersection(NumberList list2){
    NumberList intersection;
    ListNode *p = head;
                        // wat
    for(int i = 0; i < this->length(); i++){
        for(int j = 0; j < list2.length(); j++){
            if(p->data == list2.getData(j)){
                if(intersection.length() == 0){
                    intersection.appendNode(p->data);
                }
                else if (!(intersection.search(p->data) >= 0)){
                    intersection.appendNode(p->data);
                }
            }
        }
        p = p->next;
    }
    return intersection;
}


//******************************************************************************
// Deletes a node based on its location in the list.
//
// int location: the index of the node to be deleted
//******************************************************************************
void NumberList::deleteNode(int location){

    ListNode *p = head;

    if (location == 0){
        head = head->next;
        delete p;
    }

    ListNode *n;

    for(int i = 0; i < location; i++){
        n = p;
        p = p->next;
    }
    n->next = n->next->next;
    delete p;
}

//******************************************************************************
// Searches for a specific value in the data node of a list.
//
// int num: the value to search for
//
// Returns: int - the index of the value found, if not found, returns -1
//
// Throws exception if the list is empty.
//******************************************************************************
int NumberList::search(int num) {

    if (!head){
        throw "ERROR: The list is empty!";
    }

    int count = 0;
    ListNode *p = head;

    while (p){
        if (p->data == num){
            return count;
        }
        count++;
        p = p->next;
    }
    return -1;
}

//******************************************************************************
// Gets the length of a list.
//
// Returns: int - the length of the list
//******************************************************************************
int NumberList::length(){
    ListNode *p = head;
    int count = 0;

    while(p){
        p = p->next;
        count++;
    }
    return count;
}

//******************************************************************************
// Rotates the list to the right so that the last element becomes the first.
//
// int rotations: number of rotations to perform
//******************************************************************************
void NumberList::rotateList(int rotations){
    ListNode *p = head;
    ListNode *n;

    for (int i = 0; i < rotations; i++){
        while (p->next){
            n = p;
            p = p->next;
        }
        n->next = NULL;
        p->next = head;
        head = p;
    }
}

//******************************************************************************
// Splits a list into two sub lists at the 10th element.
//
// NumberList &sub_1: a container for the first sub-list
// NumberList &sub_2: a container for the second sub-list
//******************************************************************************
void NumberList::splitList(NumberList &sub_1, NumberList &sub_2){
    ListNode *p = head;

    for (int i = 0; i < 10; i++){
        sub_1.appendNode(getData(i));
        p = p->next;
    }
    for (int i = 10; p; i++){
        sub_2.appendNode(getData(i));
        p = p->next;
    }
}

//******************************************************************************
// Deletes duplicate values in a list.
//
// Returns: NumberList - A new list with no duplicate elements
//******************************************************************************
NumberList NumberList::deleteDupes(){
    NumberList cleanList;
    ListNode *p = head;

    cleanList.appendNode(p->data);

    while(p){
        if (!(cleanList.search(p->data) >= 0)){
            cleanList.appendNode(p->data);
        }
        p = p->next;
    }
    clear();
    return cleanList;
}

//******************************************************************************
// Completely empties a list of all its elements.
//******************************************************************************
void NumberList::clear(){
    ListNode *p = head;

    while (head){
        head = head->next;

        delete p;
        p = head;
    }
}

//******************************************************************************
// Neatly prints out a linked list.
//******************************************************************************
void NumberList::display() const {
    ListNode *p = head;

    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//******************************************************************************
// Neatly prints out a linked list backwards.
//******************************************************************************
void NumberList::displayBack() const {
    ListNode *p = head;
    int count = 0;

    while(p->next){
        count++;
        p = p->next;
    }
    cout << p->data << " ";

    for (int i = 1; i <= count; i++){
        p = head;
        for (int j = 0; j < (count - i); j++){
            p = p->next;
        }
        cout << p->data << " ";
    }
    cout << endl;
}
