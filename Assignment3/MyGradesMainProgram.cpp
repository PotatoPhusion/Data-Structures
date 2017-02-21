// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/22/2017
// Programming Assignment 3
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Grades stuff TODO: Change this

#include <iostream>
#include <limits>
#include "MyGradesDT.h"

using namespace std;

int main() {

    int choice;
    double input;
    MyGrades g;

    cout << "Welcome to my Grades APP." << endl;

    cout << "1. Set a Quiz Grade\n"
         << "2. Set a Programming Assignment Grade\n"
         << "3. Set a Test Grade\n"
         << "4. Show all Quiz grades\n"
         << "5. Show all Programming Assignment Grades\n"
         << "6. Show all Test Grades\n"
         << "7. Show Overall Grades\n"
         << "9. Exit the Program\n" << endl;

    do {
        try {
       //do{
            cout << "Enter your choice: ";
            cin >> choice;
//    if(choice == 1)
//        g.setQuiz(input);
//    if(choice == 2)
//        g.setPA(input);   // included these if statements for now
//    if(choice == 3)       // just to test out the functions and they seem fine
//        g.setExams(input);// I couldn't get it to work with your error catching so
//    if(choice == 4)       // to kill time I used if statements. It all looks like ass but
//        g.quizGrades();   // we can fix the formatting later.
//    if(choice == 5)
//        g.progGrades();
//    if(choice == 6)
//        g.testGrades();
//    if(choice == 7)
//        g.overallGrade();
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
        cout << endl;
    } while (choice != 9);


    return 0;
}
