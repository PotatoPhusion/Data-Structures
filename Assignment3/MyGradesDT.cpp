// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/22/2017
// Programming Assignment 3
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Grades stuff TODO: Change this

#include <iomanip>
#include <iostream>
#include <vector>
#include <limits>

#include "MyGradesDT.h"

using namespace std;

//******************************************************************************
// Adds a quiz grade to the quiz grade vector.
//
// input: The grade to be entered into the function.
//******************************************************************************
void MyGrades::setQuiz(double input)
{
    try {
        cout << "Enter a Quiz Grade: ";
        cin >> input;

        if (cin.fail()) {
            throw "That is not a number!";
        }
        else if (input < 0 || input > 10) {
            throw "Entry out of bounds! Must be between 0 and 10 inclusive.";
        }

        quiz.push_back(input);
    }
    catch (const char* error) {
        cerr << "\nERROR: " << error << endl;
        cerr << "Quiz grade not recorded!" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cerr << endl;
    }
}

//******************************************************************************
// Adds a programming assignment grade to the quiz grade vector.
//
// input: The grade to be entered into the vector.
//******************************************************************************
void MyGrades::setPA(double input)
{
    try {
        cout << "Enter a Programming Assignment Grade: ";
        cin >> input;

        if (cin.fail()) {
            throw "That is not a number!";
        }
        else if (input < 0 || input > 10) {
            throw "Entry out of bounds! Must be between 0 and 10 inclusive.";
        }

        prog.push_back(input);
    }
    catch (const char* error) {
        cerr << "\nERROR: " << error << endl;
        cerr << "Programming Assignment grade not recorded!" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cerr << endl;
    }
}

//******************************************************************************
// Adds an exam grade to the quiz grade vector.
//
// input: The grade to be entered into the function.
//******************************************************************************
void MyGrades::setExams(double input)
{
    int MAX_EXAMS = 2;          // The maximum number of exam grades allowed

    try {

        if (exams.size() == MAX_EXAMS) {
            throw "Maximum number of exam grades entered!";
        }

        cout << "Enter a Test Grade: ";
        cin >> input;

        if (cin.fail()) {
            throw "That is not a number!";
        }
        else if (input < 0 || input > 10) {
            throw "Entry out of bounds! Must be between 0 and 10 inclusive.";
        }

        exams.push_back(input);
    }
    catch (const char* error) {
        cerr << "\nERROR: " << error << endl;
        cerr << "Exam grade not recorded!" << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cerr << endl;
    }
}

//******************************************************************************
// Displays a list of all quiz grades, then finds the average and compares it to
// the maximum possible score.
//
// Returns - double: The average of the quiz grades.
//******************************************************************************
double MyGrades::quizGrades()
{
    double total = 0;
    double average;

    cout << endl;

    if(!quiz.size()) {
        cout << "Show all quiz grades with average" << endl;
        cout << "No Quizzes are recorded" << endl;
    }
    else {

        cout << "Quiz Grades are as follows: " << endl;

        for (int i = 0; i < quiz.size(); i++){
            cout << fixed << setprecision(2) << quiz[i] << " ";
            total += quiz[i];
            average = (total / quiz.size());
            }

        cout << endl;

        cout << fixed << setprecision(2) << "Average quiz grades is "
             << average << " out of 10" << endl;
    }

    return average;
}

//******************************************************************************
// Displays a list of all programming assignment grades, then finds the average
// and compares it to the maximum possible score.
//
// Returns - double: The average of the programming assignment grades.
//******************************************************************************
double MyGrades::progGrades()
{
    double total = 0;
    double average;

    cout << endl;

    if(!prog.size()){
        cout << "Show all Programming Assignment grades with average" << endl;
        cout << "No Program Grades are recorded" << endl;
    }
    else{

        cout << "Programming Assignment grades are as follows: " << endl;

        for (int i = 0; i < prog.size(); i++){
            cout << fixed << setprecision(2) << prog[i] << " ";
            total += prog[i];
            average = ((total / prog.size()) * 2);
            }

        cout << endl;

        cout << fixed << setprecision(2) << "Average programming grades is "
             << average << " out of 20" << endl;
    }

    return average;
}

//******************************************************************************
// Displays a list of all exam grades, then finds the average and compares it to
// the maximum possible score.
//
// Returns - double: The average of the exam grades.
//******************************************************************************
double MyGrades::testGrades()
{
    double total = 0;
    double average;

    cout << endl;

    if(!exams.size()){
        cout << "Show All Test Grades with Average" << endl;
        cout << "No Test Grades are recorded" << endl;
    }
    else {

        cout << "Test Grades are as follows: " << endl;

        for (int i = 0; i < exams.size(); i++){
            cout << fixed << setprecision(2) << exams[i] << " ";
            total += exams[i];
            average = ((total / exams.size()) * (2 * exams.size()));
            }

        cout << endl;

        cout << fixed << setprecision(2) << "Average Test Grades is "
             << average << " out of " << 20 * exams.size() << endl;
    }

    return average;
}

//******************************************************************************
// Displays a list of all grades of all types, then finds the average and
// compares it to the maximum possible score for each type. Then calculates the
// total score and average for all assignments.
//
// Returns - double: The average of all grades.
//******************************************************************************
double MyGrades:: overallGrade()
{
    bool flag = false;
    int total = 0;
    double average = 0;

    cout << endl;
    cout << "Show Overall Grades." << endl;
    cout << endl;
    cout << "My overall grades are as follows: " << endl;


    if(!quiz.size()) {
        cout << "No Quizzes are recorded" << endl;
    }
    else {
        average += quizGrades();
        total += 10;
        flag = true;
    }

    cout << endl;

    if(!prog.size()) {
        cout << "No Programming Assignments are recorded" << endl;
    }
    else {
        average += progGrades();
        total += 20;
        flag = true;
    }

    cout << endl;

    if(!exams.size()) {
        cout << "No Exams are recorded" << endl;
    }
    else {
        average += testGrades();
        total += (20 * exams.size());
        flag = true;
    }

    if (flag) {
        cout << "Overall Total ---> " << average << " out of " << total << endl;
    }

    return average;
}
