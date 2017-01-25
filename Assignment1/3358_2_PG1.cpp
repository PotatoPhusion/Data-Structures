// Roster Number: 2
//
// Author Name: Rafael Reza & Cullen
// Due Date: 01/30/2017
// Programming Assignment 1
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom.
//
// Description: Accepts a positive integer greater than 0
// and less than 200 and runs in through 7 different
// functions
#include <iomanip>
#include <iostream>

using namespace std;

int userInput();

int main()
{
    int x;

    cout << "Welcome to My APP." << endl;
    cout << "This APP accepts an integer from the keyboard." << endl;
    cout << "The APP Calculates and Displays the following: " << endl;

    cout << endl;

    cout << "1. Assuming that the integer represents a $$ amount, " << endl
         << "then the number of quarters, dimes, nickels, and pennies " << endl
         << "will be calculated and displayed. " << endl;

    cout << endl;

    cout << "2. Assuming that the integer represents person's age in years then, " << endl
         << "number of months, days, hours, minutes, and seconds for the person will be " << endl
         << "calculated and displayed." << endl;

    cout << endl;

    cout << "3. The numbers will be separated into its individual digits." << endl
         << "Then each digit of the integer will be displayed in English." << endl;

    cout << endl;

    cout << "4. Indicate whether or not the integer is an arm strong number." << endl;

    cout << endl;

    cout << "5. The factorial of the integer will be calculated and displayed." << endl;

    cout << endl;

    cout << "6. Indicate whether or not the integer is prime. Then, all the prime numbers " << endl
         << "between 1 and that number will also be displayed." << endl;

    cout << endl;

    cout << "7. The hailstone sequence starting at n will be calculated and " << endl
         << "displayed." << endl;

    cout << endl;

    cout << "Enter a positive integer number > 0 and < 200 ---> ";
    cin >> x;

    cout << x << endl; // error checking yo


}

int userInput()
{
    cin >> input;
    return input;
}
