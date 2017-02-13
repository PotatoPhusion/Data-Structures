// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 02/13/2017
// Programming Assignment 2
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Takes user input, builds a 2d vector and then
// finds the totals for rows, columns, and diagonals
// as well as determining if they have a perfect number.

#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//takes user input and builds a 2d vector
void matrix(int);

//finds the total of the diagonal at first and last digit
bool diagonals(vector<vector<int> >, int);

//finds the total for the each rows
bool sumRow(vector<vector<int> >, int);

//finds the total for each column
bool sumColumn(vector<vector<int> >, int);


int main() {

    int input;

    cout << "Welcome to my perfect matrix program. The function of the program "
         << "is to:\n" << endl;

    cout << "\t1. Allow the user to enter the size of the perfect matrix, such"
         << "\n\t " << setw(15) << "as N, n >= 2." << endl;

    cout << "\t2. Create a 2D vector array of size N x N." << endl;

    cout << "\t3. Populate the 2D vector array with distinct random numbers."
         << endl;

    cout << "\t4. Display the sum for each row, column, and diagonals.\n\t   "
         << "Then determine whether the numbers in N x N vector array are "
         << "perfect\n\t  "
         << setw(16) << "matrix numbers." << endl << endl;

    char choice;

    do {

        cout << "Enter the size of the matrix: ";
        cin >> input;

        cout << endl;

        // Catches bad inputs
        while(input < 2 || cin.fail()) {

            if (cin.fail()) {

                cout << "Error! This is not an integer." << endl
                     << "Please enter a positive integer." << endl << endl;
            }
            else if (input < 2) {

                cout << "Error! Number must be >= 2" << endl << endl;
            }

            cin.clear();                   // Clears bad input flag
            cin.ignore(256, '\n');		   // Clears input buffer
            cout << "Enter the size of the matrix: ";
            cin >> input;
            cout << endl;
        }

        cout << "The perfect matrix that is created for size " << input << ":\n";
        matrix(input);


        cout << "Would you like to find another perfect matrix? y/n: ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        // Catches bad inputs
		while(choice != 'Y' && choice != 'N' || cin.fail())
        {
            cin.clear();                   // Clears bad input flag
            cin.ignore(256, '\n');		   // Clears input buffer
            cout << "Error! Invalid choice - Must be y || Y || n || N" << endl
                 << endl;
            cout << "Would you like to find another perfect matrix? y/n: ";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;
		}
    } while (choice != 'N');


    cout << "This perfect matrix algorithm is implemented by "
         << "Rafael Reza & Cullen Sturdivant\n"
         << "February 12, 2017" << endl;

    return 0;
}

//******************************************************************************
//A function that creates and builds a 2d vector dependent on user input
//
//input: The user input that sizes the 2d vector
//
//prints out the user created vector as well as sums for rows,
//columns, and diagonals.
//******************************************************************************
void matrix(int input)
{
    int total = 0;
    int perfNum = 0;
    int perfect = true;

    srand(time(0));

    cout << left << fixed;

    vector<vector<int> > v;

    for (int i = 0; i < input; i++)
    {
        vector<int> w;
        for (int j = 0; j < input; j++)
        {
            w.push_back(rand() % 120);
        }
        v.push_back(w);
    }

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << setw(6) << v[i][j];
            total += v[i][j];
        }
        cout << "\n\n" << endl;
    }

    perfNum = total / 3;    // 3 is based off of the formula for perfect numbers

    cout << endl;

    cout << "The perfect number is: " << perfNum << endl;

    cout << endl;


    perfect = sumRow(v, perfNum);
    perfect = sumColumn(v, perfNum) && perfect;
    perfect = diagonals(v,perfNum) && perfect;

    if (perfect) {
        cout << "The above is a perfect matrix." << endl << endl;
    }
    else {
        cout << "The above is not a perfect matrix." << endl << endl;
    }

}

//******************************************************************************
// A function that calculates the sum across the diagonals of a matrix
//
// v: The 2D vector to be evaluated
// perfNum: The perfect number of the passed matrix
//
// Returns bool: True if all sums equal perfect number, false otherwise
//******************************************************************************
bool diagonals(vector<vector<int> >v, int perfNum) {
    int mainDiag = 0;
    int secondDiag = 0;
    bool flag = true;

    for(int i = 0; i < v.size(); i++) {
        mainDiag += v[i][i];
    }

    for (int i = 0; i < v.size(); i++) {

        int j = v.at(i).size() - 1 - i;
        secondDiag += v[i][j];
    }

    cout << left << fixed;
    cout << setw(36) << "Sum of numbers in first diagonal" << setw(6) << " = "
         << mainDiag << endl;
    cout << setw(36) << "Sum of numbers in second diagonal" << setw(6) << " = "
         << secondDiag << endl;
    cout << endl;

    if (mainDiag != perfNum || secondDiag != perfNum)
        flag = false;

    return flag;
}

//******************************************************************************
// A function that calculates the sum for all rows in a matrix
//
// v: The 2D vector to be evaluated
// perfNum: The perfect number of the passed matrix
//
// Returns bool: True if all sums equal perfect number, false otherwise
//******************************************************************************
bool sumRow(vector<vector<int> > v, int perfNum) {

    int total = 0;
    bool flag = true;

    cout << left << fixed;

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            total += v[i][j];
        }
        cout << setw(30) << "Sum of numbers in Row" << "#" << setw(5) << i + 1
             << setw(6) << " = " << total << endl;


        if(total != perfNum)
            flag = false;

        total = 0;
    }
    cout << endl;

    return flag;
}

//******************************************************************************
// A function that calculates the sum for all columns in a matrix
//
// v: The 2D vector to be evaluated
// perfNum: The perfect number of the passed matrix
//
// Returns bool: True if all sums equal perfect number, false otherwise
//******************************************************************************
bool sumColumn(vector<vector<int> > v, int perfNum) {

    int total = 0;
    bool flag = true;

    cout << left << fixed;

    for (int i = 0; i < v.at(0).size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            total += v[j][i];
        }
        cout << setw(30) << "Sum of numbers in Column" << "#" << setw(5)<< i + 1
             << setw(6) << " = " << total << endl;

        if (total != perfNum)
            flag = false;

        total = 0;
    }
    cout << endl;

    return flag;
}
