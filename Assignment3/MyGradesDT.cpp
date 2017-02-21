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
#include "MyGradesDT.h"

using namespace std;

void MyGrades:: setQuiz(double input)
{
    cout << "Enter a Quiz Grade ";
    cin >> input;
    quiz.push_back(input);
}

void MyGrades:: setPA(double input)
{
    cout << "Enter a Programming Assignment Grade ";
    cin >> input;
    prog.push_back(input);
}

void MyGrades:: setExams(double input)
{
    cout << "Enter a Test Grade ";
    cin >> input;
    exams.push_back(input);
}

double MyGrades:: quizGrades()
{
    double total = 0;
    double average;

    cout << endl;
    cout << "Show all quiz grades with average" << endl;

    if(!quiz.size())
         cout << "No Quizzes are recorded" << endl;
    else
        cout << "Quiz Grades are as follows " << endl;
        for (int i = 0; i < quiz.size(); i++)
        {
            cout << fixed << setprecision(2) << quiz[i] << " ";
            total += quiz[i];
            average = (total / quiz.size());
        }
    cout << endl;

    cout << fixed << setprecision(2) << "Average quiz grades is "
         << average << " out of 10";
}

double MyGrades:: progAssign()
{
    double total = 0;
    double average;

    cout << endl;
    cout << "Show all Programming Assignment grades with average" << endl;

    if(!prog.size())
         cout << "No Program Grades are recorded" << endl;
    else
        cout << "Programming Assignment grades are as follows " << endl;
        for (int i = 0; i < prog.size(); i++)
        {
            cout << fixed << setprecision(2) << prog[i] << " ";
            total += prog[i];
            average = (total / prog.size() * 2);
        }
    cout << endl;

    cout << fixed << setprecision(2) << "Average quiz grades is "
         << average << " out of 20";
}

double MyGrades:: testGrades()
{
    double total = 0;
    double average;

    cout << endl;
    cout << "Show All Test Grades with Average" << endl;

    if(!exams.size())
         cout << "No Test Grades are recorded" << endl;
    else
        cout << "Test Grades are as follows " << endl;
        for (int i = 0; i < exams.size(); i++)
        {
            cout << fixed << setprecision(2) << exams[i] << " ";
            total += exams[i];
            average = (total / exams.size() * 2);
        }
    cout << endl;

    cout << fixed << setprecision(2) << "Average Test Grades is "
         << average << " out of 40";
}
