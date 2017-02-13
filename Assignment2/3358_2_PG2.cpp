// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/13/2017
// Programming Assignment 2
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Vectors and matrices and stuff

#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void matrix(int);
void diagonals(vector<vector<int> >);
void sumRow(vector<vector<int> >);


int main() {

    int input;

    cout << "Welcome to my perfect matrix program. The function of the program "
         << "is to:\n" << endl;

    cout << "\t1. Allow the user to enter the size of the perfect matrix, such\n\t "
         << setw(15) << "as N, n >= 2." << endl;

    cout << "\t2. Create a 2D vector array of size N x N." << endl;

    cout << "\t3. Populate the 2D vector array with distinct random numbers."
         << endl;

    cout << "\t4. Display the sum for each row, column, and diagonals.\n\t "
         << "Then determine whether the numbers in N x N vector array are "
         << "perfect\n\t"
         << setw(16) << "matrix numbers." << endl << endl;

    cout << "Enter the size of the matrix: ";
    cin >> input;

    cout << endl;

    // Catches bad inputs
    while(input <= 2 || cin.fail()) {

        if (cin.fail()) {

            cout << "Error! This is not an integer." << endl
                 << "Please enter a positive integer." << endl << endl;
        }
        else if (input <= 2) {

            cout << "Error! Number must be > 0 and < 200" << endl << endl;
        }

        cin.clear();                   // Clears bad input flag
        cin.ignore(256, '\n');		   // Clears input buffer
        cout << "Enter a positive integer number > 0 and < 200 ---> ";
        cin >> input;
        cout << endl;
    }

    cout << "The perfect matrix that is created for size " << input << ":\n";

    matrix(input);

    return 0;
}

void matrix(int input)
{
    int total = 0;
    int perfNum = 0;

    srand(time(0));

    vector<vector<int> > v;

    for (int i = 0; i < input; i++)
    {
        vector<int> w;
        for (int j = 0; j < input; j++)
        {
            w.push_back(rand() % 10);
        }
        v.push_back(w);
    }

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " " ;
            total += v[i][j];
        }
        cout << endl;
    }

    perfNum = total / 3;     // 3 is based off of the formula for perfect numbers

    cout << endl;

    cout << "The perfect number is: " << (perfNum);

    cout << endl;

    diagonals(v); // here it is my friend, the first diagonal.
    sumRow(v);
}

//got the diagonal into its own function now but,
//I placed it in the matrix function. Not sure if that's
//exactly correct or the style required...
void diagonals(vector<vector<int> >v) {
    int mainDiag = 0;
    int secondDiag = 0;

    for(int i = 0; i < v.size(); i++) {
        mainDiag += v[i][i];
    }

    for (int i = 0; i < v.size(); i++) {

        int j = v.at(i).size() - 1 - i;
        secondDiag += v[i][j];
    }

    cout << "Sum of numbers in first diagonal is: " << mainDiag << endl;
    cout << "Sum of numbers in second diagonal is: " << secondDiag << endl;
}

void sumRow(vector<vector<int> > v) {

    int total = 0;

    cout << fixed;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            total += v[i][j];
        }
        cout << "Sum of numbers in Row" << setw(6) << "#" << i + 1
             << setw(6) << " = " << total << endl;
        total = 0;
    }

}
