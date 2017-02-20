// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/22/2017
// Programming Assignment 3
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Grades stuff TODO: Change this

#include <iostream>

using namespace std;

int main() {

    int choice;

    do {
        try {
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                throw "That is not a number!";
            }
        }
        catch (const char* error) {
            cerr << "\nERROR:" << error << "\n"
                 << "Please choose a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);


    return 0;
}
