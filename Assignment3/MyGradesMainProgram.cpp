// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/22/2017
// Programming Assignment 3
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// The driver function for testing the MyGradesDT class

#include <iostream>
#include <limits>
#include "MyGradesDT.h"

using namespace std;

int main() {

    int choice;
    double input;
    MyGrades g;

    cout << "Welcome to my Grades APP.\n" << endl;


    do {

        cout << "Main Menu" << endl << endl;
        cout << "1. Set a Quiz Grade\n"
             << "2. Set a Programming Assignment Grade\n"
             << "3. Set a Test Grade\n"
             << "4. Show all Quiz grades\n"
             << "5. Show all Programming Assignment Grades\n"
             << "6. Show all Test Grades\n"
             << "7. Show Overall Grades\n"
             << "9. Exit the Program\n" << endl;

        try {

            cout << "Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
                throw "That is not a number!";
            }
            else if (choice < 1 || choice == 8 || choice > 9) {
                throw "That is not a valid menu option!";
            }

            switch (choice) {
            case 1:
                g.setQuiz(input);
                break;
            case 2:
                g.setPA(input);
                break;
            case 3:
                g.setExams(input);
                break;
            case 4:
                g.quizGrades();
                break;
            case 5:
                g.progGrades();
                break;
            case 6:
                g.testGrades();
                break;
            case 7:
                g.overallGrade();
                break;
            default:
                break;
            }

        }
        catch (const char* error) {
            cerr << "\nERROR: " << error << "\n"
                 << "Please choose a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    } while (choice != 9);

    cout << "Implemented by Rafael Reza & Cullen Sturdivant" << endl
         << "February, 2017" << endl;

    return 0;
}
