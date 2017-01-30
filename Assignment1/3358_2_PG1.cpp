// Roster Number: 2
//
// Author Names: Rafael Reza & Cullen Sturdivant
// Due Date: 01/30/2017
// Programming Assignment 1
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Description: Accepts a positive integer greater than 0
// and less than 200 and runs it through 7 different
// functions

#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <cmath>

using namespace std;
//finds amount of quarters, nickels, dimes, & pennies from input
void currency(int);
//finds the age in months, days, hours, minutes, & seconds from input
void age(int);
//separates the users input and prints in english each digit
void separate(int);
//finds the armstrong number of input
void armStrong(int);
//finds factorial of input
void factorial(int);
//determines if input is prime
bool isPrime(int);
//prints out to see if it is prime or not
void outputPrime(int);
//finds all prime numbers between 1 and input
void findPrimes(int);
//finds the hailstone sequence of input
void hailstone(int);

int main()
{

    cout << "Welcome to My APP." << endl;
    cout << "This APP accepts an integer from the keyboard." << endl;
    cout << "The APP Calculates and Displays the following: " << endl;

    cout << endl;

    cout << "1. Assuming that the integer represents a $$ amount, " << endl
         << "then the number of quarters, dimes, nickels, and pennies " << endl
         << "will be calculated and displayed. " << endl;

    cout << endl;

    cout << "2. Assuming that the integer represents person's age in years "
         << "then, " << endl
         << "number of months, days, hours, minutes, and seconds for the "
         << "person will be " << endl
         << "calculated and displayed." << endl;

    cout << endl;

    cout << "3. The numbers will be separated into its individual digits."
         << endl
         << "Then each digit of the integer will be displayed in English."
         << endl;

    cout << endl;

    cout << "4. Indicate whether or not the integer is an arm strong number."
         << endl;

    cout << endl;

    cout << "5. The factorial of the integer will be calculated and displayed."
         << endl;

    cout << endl;

    cout << "6. Indicate whether or not the integer is prime. Then, all the "
         << "prime numbers " << endl
         << "between 1 and that number will also be displayed." << endl;

    cout << endl;

    cout << "7. The hailstone sequence starting at n will be calculated and "
         << endl
         << "displayed." << endl;

    cout << endl;

    char choice;

    do
    {
        int input; //input from the user

        cout << "Enter a positive integer number > 0 and < 200 ---> ";
        cin >> input;
        cout << endl;

        // Catches bad inputs
        while(input < 1 || input > 200 || cin.fail())
        {
            if (cin.fail())
            {
                cout << "Error! This is not an integer." << endl
                     << "Please enter a positive integer." << endl << endl;
            }
            else if (input < 1 || input > 200)
            {
                cout << "Error! Number must be > 0 and < 200" << endl << endl;
            }

            cin.clear();                   // Clears bad input flag
            cin.ignore(256, '\n');		   // Clears input buffer
            cout << "Enter a positive integer number > 0 and < 200 ---> ";
            cin >> input;
            cout << endl;
        }

        currency(input);
        cout << endl;
        age(input);
        cout << endl;
        separate(input);
        cout << endl;
        armStrong(input);
        cout << endl;
        factorial(input);
        cout << endl;
        outputPrime(input);
        cout << endl;
        findPrimes(input);
        cout << endl;
        hailstone(input);
        cout << endl;

        cout << "Would you like to try another number?\n"
             << "Enter y || Y for Yes or n || N for No ---> ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        // Catches bad inputs
		while(choice != 'Y' && choice != 'N' || cin.fail())
        {
            cin.clear();                   // Clears bad input flag
            cin.ignore(256, '\n');		   // Clears input buffer
            cout << "Error! Invalid choice - Must be y || Y || n || N" << endl
                 << endl << "Would you like to try another number?\n"
                 << "Enter y || Y for Yes or n || N for No ---> ";
            cin >> choice;
            choice = toupper(choice);
            cout << endl;
		}

    } while (choice != 'N');

    cout << "\nThis APP was developed by Rafael Reza & Cullen Sturdivant\n"
         << "January 29, 2017" << endl;

}

//******************
//finds amount of quarters, nickels, dimes, & pennies from input
//
//parameter 1 - input
//
//
//multiplies input by amount of quarters, nickels, dimes, &
//pennies to see how many make up the input
//******************
void currency(int input)
{
    int quarters = 4;
    int dimes = 10;
    int nickels = 20;
    int cents = 100;

    cout << "Currency Calculation" << endl;
    cout << endl;
    cout << "$" << input << " is equivalent to: " << endl;
    cout << endl;
    cout << input * quarters << " quarter/s" << endl;
    cout << input * dimes << " dime/s" << endl;
    cout << input * nickels << " nickel/s" << endl;
    cout << input * cents << " cent/s" << endl;
}

//******************
//finds the age in months, days, hours, minutes, & seconds from input
//
//parameter 1 - input
//
//multiplies input by months, days, hours, minutes, & seconds
//to figure out how long those would be respectively
//******************
void age(int input)
{
    int month = 12;
    int days = 365;
    int hours = 24 * 365;
    int minutes = 60 * hours;
    int seconds = 60 * minutes;

    cout << "Age Calculation" << endl;
    cout << endl;
    cout << "Assuming that you are " << input << " years old, then" << endl;
    cout << endl;
    cout << "You are " << month * input << " months old" << endl;
    cout << "You are " << days * input << " days old" << endl;
    cout << "You are " << hours * input << " hours old" << endl;
    cout << "You are " << minutes * input << " minutes old" << endl;
    cout << "You are " << static_cast<long long>(seconds) * input
         << " seconds old" << endl;
}

//******************
//separates the users input and prints in english each digit
//
//parameter 1 - input
//
//spaces out a multiple digit input and spells out
//in english each digit
//******************
void separate(int input)
{
    stringstream lengthOfInput;
    lengthOfInput << input;

    cout << "Separating digits for the integer: " << input << endl;

    for (int i = 0; i < lengthOfInput.str().size(); i++)
    {
        cout << lengthOfInput.str().at(i) << "  ";

    }

    cout << endl;

    for (int k = 0; k < lengthOfInput.str().size(); k++)
    {
        switch(lengthOfInput.str().at(k))
            {
                case '0':
                cout << "Zero" << "  ";
                break;
                case '1':
                cout << "One" << "   ";
                break;
                case '2':
                cout << "Two" << "   ";
                break;
                case '3':
                cout << "Three" << "   ";
                break;
                case '4':
                cout << "Four" << "   ";
                break;
                case '5':
                cout << "Five" << "   ";
                break;
                case '6':
                cout << "Six" << "   ";
                break;
                case '7':
                cout << "Seven" << "   ";
                break;
                case '8':
                cout << "Eight" << "   ";
                break;
                case '9':
                cout << "Nine" << "   ";
                break;
            }
    }
    cout << endl;
}

//******************
//finds the armstrong number of input
//
//parameter 1 - input
//
//cubes each digit to see if they equal the input from
//the user
//******************
void armStrong(int input)
{
    int armNum;
    int sum = 0;
    int flag = input;

    while ( input != 0)
    {
        armNum = input % 10;
        sum += armNum * armNum * armNum;
        input /= 10;
    }

    if (sum == flag)
        cout << flag << " is an Armstrong number." << endl;
    else
        cout << flag << " is not an Armstrong number." << endl;
}

//******************
//finds factorial of input
//
//parameter 1 - input
//
//determines the total factorial of input from user
//by multiplying from 1 to number inputted
//******************
void factorial(int input)
{
    long double total = 1;

    cout << "Factorial of " << input << " = ";

    if( input == 0)
        cout << total << endl;
    else
    {
        for (int i = 1; i <= input; i++)
        {
            total *= i;
        }
        cout << total << endl;
    }
}

bool isPrime(int input)
{
    bool prime = false;

    for (int i = 2; i <= ceil(sqrt(input)); i++)
    {
        if (input % i == 0)
        {
            prime = false;
            i = sqrt(input) + 1;   //to end the loop
        }
        else
        {
            prime = true;
        }
    }
    return prime;
}

void outputPrime(int input)
{
    if(isPrime(input))
    {
        cout << input << " is a prime number" << endl;
    }
    else
    {
        cout << input << " is not a prime number" << endl;
    }
}

void findPrimes(int input)
{
    cout << "All prime numbers between 1 and " << input << " are:" << endl;
    for (int i = 1; i <= input; i++)
    {
        if (isPrime(i))
            cout << setw(5) << i << " is a prime number" << endl;
    }
    cout << endl;
}

void hailstone(int input)
{
    int current = input;

    cout << "The Hailstone Sequence starting at " << input << " is:" << endl;
    cout << current << "   ";

    while (current != 1)
    {
        if (current % 2 == 0)
        {
            current /= 2;
        }
        else if(current % 2 == 1)
        {
            current = (current * 3) + 1;
        }
        cout << current << "   ";
    }
    cout << endl << endl;
}
