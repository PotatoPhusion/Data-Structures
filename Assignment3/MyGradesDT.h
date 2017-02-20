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
    void setQuiz(vector);
    void setPA(vector);
    void setExams(vector);
    double quizGrades(vector);
    double progAssign(vector);
    double testGrades(vector);
    double overallGrade(vector, vector, vector);


};
