// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 04/26/2017
// Programming Assignment 7
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// A program demonstrating the use of hash tables

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

class Hashtable {
private:
    int size = 0;
    int *intArr;
    int *numHash;
    int *collisions;
public:
    Hashtable(int);
    int getSize();
    void hash(int);
    void searchTable();
    void insert();
    bool deleteValue();
    void displayStats();
    void printTable();
};


Hashtable::Hashtable(int s){
    size = s;

    intArr = new int[size];
    numHash = new int[size];
    collisions = new int[size];

    for (int i = 0; i < size; i++) {
        intArr[i] = -1;
        numHash[i] = 0;
        collisions[i] = 0;
    }
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
int Hashtable::getSize(){
    return size;
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
void Hashtable::hash(int input){

    int increment = 0;
    bool hashed = false;

    while (!hashed){
        int i = ((input + increment) % size);
        numHash[i]++;
        if (intArr[i] == -1){
            intArr[i] = input;
            hashed = true;
        }
        else {
            increment++;
            collisions[i]++;
        }
    }
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
void Hashtable::searchTable(){
    int num;
    cout << "Enter the number you would like to search for (Between 100 and 500"
         << "): ";
    cin >> num;

    for (int i = 0; i < size; i++){
        if (intArr[i] == num){
            cout << "The value " << num << " was found at position " << i + 1
                 << endl << endl;
            return;
        }
    }
    cout << "The value you entered could not be found" << endl << endl;
    return;
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
void Hashtable::insert(){
    int num;
    cout << "Enter the number you would like to insert (Between 100 and 500"
         << "): ";
    cin >> num;

    hash(num);
    cout << endl;
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
bool Hashtable::deleteValue(){
    int num;
    cout << "Enter the number you would like to delete (Between 100 and 500"
         << "): ";
    cin >> num;

    for (int i = 0; i < size; i++){
        if (intArr[i] == num){
            intArr[i] = -1;
            cout << "The value was successfully deleted!" << endl << endl;
            return true;
        }
    }
    cout << "The value could not be found or deleted!" << endl << endl;
}

//==============================================================================
// [Description]
//
// [Parameters]
//
// [Returns]
//
//==============================================================================
void Hashtable::displayStats(){

    cout << left;
    cout << "Number of hashes performed by location: " << endl;
    cout << setw(6) << "Pos" << "Hashes" << endl;
    for (int i = 0; i < size; i++){
        cout << setw(6) << i+1 << numHash[i] << endl;
    }
    cout << endl;

    cout << "Number of collisions/linear probings by location: " << endl;
    cout << setw(6) << "Pos" << "Collisions" << endl;
    for (int i = 0; i < size; i++){
        cout << setw(6) << i+1 << collisions[i] << endl;
    }
    cout << endl;
}

//==============================================================================
// [Description]
//
//==============================================================================
void Hashtable::printTable(){
    for (int i = 0; i < size/2; i++){
        cout << intArr[i] << "  ";
    }
    cout << endl;
    for (int i = (size / 2); i < size; i++){
        cout << intArr[i] << "  ";
    }
}

int main()
{
    srand(time(0));

    Hashtable hashObj(30);

    for (int i = 0; i < (hashObj.getSize()/2); i++){
        int random = (rand() % 400) + 100;
        hashObj.hash(random);
    }

    cout << "\t\t=== Welcome to our Hash Table Program. ===" << endl;
    cout << "\n\tThis program will demonstrate how a Hash Table works "
         << "\n\tand allow the user to perform basic operations with the table."
         << endl << endl;

    cout << "The following are the contents of the Hash Table:" << endl << endl;

    hashObj.printTable();

    cout << endl << endl;

    char choice;

    do {
        try {
            cout << "   Main Menu" << endl;
            cout << "1. Display the Hash Table" << endl
                 << "2. Search for a number in the table" << endl
                 << "3. Insert a new number into the table" << endl
                 << "4. Delete a number from the table" << endl
                 << "X. Exit the program" << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 'x' || choice == 'X'){
                break;
            }
            if (choice < 49 || choice > 52){
                throw "Invalid Option!";
            }
            else {
                switch (choice){
                case '1':
                    cout << "The following are the contents of the Hash Table:"
                         << endl;

                    hashObj.printTable();

                    cout << endl << endl;
                    break;
                case '2':
                    hashObj.searchTable();
                    break;
                case '3':
                    hashObj.insert();
                    break;
                case '4':
                    hashObj.deleteValue();
                    break;
                default:
                    break;
                }
            }
        }
        catch(const char* error){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ERROR: " << error << endl << endl;
        }
    } while(choice != 'x' || choice != 'X');

    hashObj.displayStats();

    cout << "This program was implemented by Rafael Reza and Cullen Sturdivant"
         << "\nApril 2017" << endl;
}
