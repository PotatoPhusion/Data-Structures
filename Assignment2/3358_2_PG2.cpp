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
void diagonal1(vector<vector<int> >);


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

    cout << "The perfect matrix that is created for size " << input << ":\n";

    matrix(input);

    return 0;
}

void matrix(int input)
{
    int total = 0;
    int perfNum = 3;

    srand(time(0));

    vector<vector<int> >v;

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

    cout << endl;

    cout << "The perfect number is: " << (total / perfNum);

    cout << endl;

    diagonal1(v); // here it is my friend, the first diagonal.
}

//got the diagonal into its own function now but,
//I placed it in the matrix function. Not sure if that's
//exactly correct or the style required...
void diagonal1(vector<vector<int> >v)
{
    int diagonal = 0;

    for(int i = 0; i < v.size(); i++)
    {
        diagonal += v[i][i];
    }
    cout << "Sum of numbers in first diagonal is: " << diagonal << endl;
}
