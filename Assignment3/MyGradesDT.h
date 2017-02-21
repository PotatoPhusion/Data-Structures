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

using namespace std;

class MyGrades
{
    private:
    vector<double> quiz;
    vector<double> prog;
    vector<double> exams;

    public:
    void setQuiz(double); // took out vector argument seemed to work better
    void setPA(double);
    void setExams(double);
    double quizGrades(); // lets see if it'll work without vector arg edit: it did
    double progAssign();
    double testGrades();
    double overallGrade(vector<double>, vector<double>, vector<double>);
    //pretty sure I don't need these arguments now, will fix later


};
