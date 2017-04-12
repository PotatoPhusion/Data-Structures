// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 04/12/2017
// Programming Assignment 6
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Provides examples of how recursive functions work

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>


using namespace std;

void printArray(int[], int);
void printArray(int[], int, char);
void tableOfSquares(int[], int, int);
int power(int, int);
int sumOfSquares(int, int, long int&);
void maxMember(int[], int, int&, int&);
void bubbleSort(int[], int);
bool isMember(int[], int, int);
bool notMember(int[], int, int, int first = 0);
bool isPrime(int);
void isItPrime(int[], int);

int main()
{
    srand(time(0));     // Seeding RNG

    cout << "Thinking Recursively" << endl << endl;

    cout << "The function of this program is to\n"
         << "use recursion to :-" << endl;
    cout << endl;
    cout << "\t1. Display squares of integers in ascending"
         << "\n\t" << setw(48)
         << "order from 1 to the last element in the array" << endl;
    cout << "\t2. Raise the first number to a power 2" << endl;
    cout << "\t3. Return the sums of squares of the numbers"
         << "\n\t" << setw(45)
         << "from 0 to a the fifth element in the array" << endl;
    cout << "\t4. Search the array for the array's min and max values" << endl;
    cout << "\t5. Sort the array in ascending order" << endl;
    cout << "\t6. Search the array for the first value in the array" << endl;
    cout << "\t7. Search the array for the number 600." << endl;
    cout << "\t8. Determine if a number is prime (process all array values)\n"
         << endl;

    cout << left;

    char input;
    int length = 0;
    int *arr;
    int b = 2;

    do {
        try {
            cout << "Select from the following menu" << endl;
            cout << "A. Enter array size that is > 4." << endl
                 << "X. Terminate the program.     ";
            cin >> input;
            input = toupper(input);
            cout << endl;

            if (cin.fail()){
                throw "*** Invalid Option ***";
            }
            else if (input != 'A' && input != 'X'){
                throw "*** Invalid Option ***";
            }

            if (input == 'A'){

                cout << "Enter Array Size: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bool flag;
                do {
                    flag = false;
                    try {
                        cin >> length;

                        if (cin.fail()){
                            throw "Enter an integer not a char: ";
                        }
                        else if (length < 5){
                            throw "*** Enter Array Size That is > 4: ";
                        }
                    }
                    catch (const char* error){
                        flag = true;
                        cerr << endl << "*** Invalid Array Size Value ***" << endl;
                        cerr << error;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (flag);

                arr = new int[length];

                for (int i = 0; i < length; i++){
                    arr[i] = (rand() % 475) + 25;
                }
//================================== Part 3 ====================================
                cout << "The generated array is: ";
                printArray(arr, length);
                cout << endl << endl;

//================================== Part 4 ====================================
                cout << "Table of square values 1 - " << arr[length-1] << endl;
                cout << endl;
                cout << setw(6) << "N" << "N Squared" << endl;
                tableOfSquares(arr, length, 1);
                cout << endl;

//================================== Part 5 ====================================
                cout << "Power Function:" << endl
                     << arr[0] << " raised to the 2nd power is: "
                     << power(arr[0], 2);
                cout << endl << endl;

//================================== Part 6 ====================================
                long int total = 0;
                cout << "Sum of squares between 0 and " << arr[length - 2]
                     << " is: ";
                total = sumOfSquares(0, arr[length-2], total);
                cout << total << endl << endl;

//================================== Part 7 ====================================
                int min = 501;
                int max = 0;

                maxMember(arr, length, min, max);

                cout << "Min Number of ( ";
                printArray(arr, length, ',');
                cout << " ) is : " << min << endl;
                cout << "Max Number of ( ";
                printArray(arr, length, ',');
                cout << " ) is : " << max << endl << endl;

//================================== Part 8 ====================================
                cout << "Sorted array" << endl;
                bubbleSort(arr, length);
                printArray(arr, length);
                cout << endl << endl;

//================================== Part 9 ====================================
                bool found = false;
                cout << "Member Functions:" << endl;
                cout << "Does the array:  ";
                printArray(arr, length);
                cout << "  have the number " << arr[3] << "? ";
                found = isMember(arr, length, arr[3]);
                if (found){
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }

//================================== Part 10 ===================================
                cout << "Does the array:  ";
                printArray(arr, length);
                cout << "  have the number " << 600 << "? ";
                found = notMember(arr, length - 1, 600);
                if (found){
                    cout << "YES" << endl;
                }
                else {
                    cout << " NO" << endl;
                }
                cout << endl << endl;

//================================== Part 11 ===================================
                cout << "Is it prime:" << endl;
                isItPrime(arr, length);
                cout << endl << endl;
            }
        }
        catch (const char* error) {
            cerr << error << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << endl;
        }

    } while (input != 'X');


    delete[] arr;

    cout << "This application was written by Rafael Reza & Cullen Sturdivant "
         << endl << "April 2017" << endl;

}

//==============================================================================
// [Description]
// Prints out an array to the console.
// [Params]
// int arr[]: The array to be printed
// int length: the size of the array
// [Returns]
// Nothing
//==============================================================================
void printArray(int arr[], int length){
    for (int i = 0; i < length; i++){
        cout << arr[i];
        if (i != (length - 1)){
            cout << "  ";
        }
    }
}

//==============================================================================
// [Description]
// Prints out an array to the console with a character between each element.
// [Params]
// int arr[]: The array to be printed
// int length: the size of the array
// char divider: the character to place between each element
// [Returns]
// Nothing
//==============================================================================
void printArray(int arr[], int length, char divider){
    for (int i = 0; i < length; i++){
        cout << arr[i];
        if (i != (length - 1)){
            cout << " " << divider << " ";
        }
    }
}

//==============================================================================
// [Description]
// Prints out a table of all numbers and their squares up to the value of the
//  last element in the array.
// [Params]
// int arr[]: To access the last element of given array
// int length: the size of the array
// int start: used to recursively increment the function
// [Returns]
// Nothing
//==============================================================================
void tableOfSquares(int arr[], int length, int start){
    cout << setw(6) << start << power(start, 2) << endl;
    if (start == arr[length-1])
        return;
    tableOfSquares(arr, length, start + 1);
}

//==============================================================================
// [Description]
// Takes a number as a base and raises it by some exponent.
// [Params]
// int base: the base of the number to be raised
// int exp: the power to raise the base by
// [Returns]
// The final number after the operation.
//==============================================================================
int power(int base, int exp){

    if (exp == 0)
        return (1);
    else if (exp == 1)
        return (base);
    else{
        return (base * power(base, exp - 1));
    }
}

//==============================================================================
// [Description]
// Finds the sum of all squares up to the stop value.
// [Params]
// int current: Used recursively to track values
// int stop: the value to stop at
// long int& total: The total sum of all squares
// [Returns]
// Total sum of all squares
//==============================================================================
int sumOfSquares(int current, int stop, long int &total){
    total += power(current, 2);
    if (current == stop)
        return total;
    sumOfSquares(++current, stop, total);
}

//==============================================================================
// [Description]
// Finds the maximum and minimum numbers in an array.
// [Params]
// int arr[]: The array to search
// int length: the length of the array
// int& min: the minimum value in the array
// int& max: the maximum value in the array
// [Returns]
// Nothing
//==============================================================================
void maxMember(int arr[], int length, int& min, int& max){
    if (arr[length-1] == -1){
        return;
    }
    if (arr[length-1] > max){
        max = arr[length-1];
    }
    if (arr[length-1] < min){
        min = arr[length-1];
    }
    if (length > 1){
        maxMember(arr, length - 1, min, max);
    }
}

//==============================================================================
// [Description]
// Sorts and array in descending order with a bubble sort.
// [Params]
// int arr[]: the array to be sorted
// int size: the size of the array
// [Returns]
// Nothing
//==============================================================================
void bubbleSort(int arr[], int size){

    if(size == 1){
        return;
    }
    else{
        for(int i = 0; i < size - 1; i++){
            if (arr[i] < arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    bubbleSort(arr, size - 1);
}

//==============================================================================
// [Description]
// Uses a linear search to find a given value.
// [Params]
// int arr[]: The array to search
// int length: The length of the array
// int value: the value to be found
// [Returns]
// True if value is found, false otherwise
//==============================================================================
bool isMember(int arr[], int length, int value){
    if (arr[length - 1] == value){
        return true;
    }
    else if (length == 1){
        return false;
    }
    else {
        isMember(arr, length - 1, value);
    }
}

//==============================================================================
// [Description]
// Uses a binary search to find a value in an array.
// [Params]
// int arr[]: the array to search
// int last: equivalent to length, also used recursively to narrow search
// int value: The value to search for in the array
// int first: used recursively to narrow search, default is 0
// [Returns]
// True if value is found, false otherwise
//==============================================================================
bool notMember(int arr[], int last, int value, int first){

    int mid;

    if (first > last){
        return false;
    }

    mid = (first + last) / 2;

    if (arr[mid] == value){
        return true;
    }
    else if (arr[mid] > value){
        return notMember(arr, last, value, mid + 1);
    }
    else if (arr[mid] < value){
        return notMember(arr, mid - 1, value, first);
    }
    return false;
}

//==============================================================================
// [Description]
// Determines whether a number is prime or not.
// [Params]
// int input: the number to determine if prime
// [Returns]
// True if prime, false otherwise
//==============================================================================
bool isPrime(int input){
    bool prime = false;

    for (int i = 2; i <= ceil(sqrt(input)); i++){
        if (input % i == 0){
            prime = false;
            i = sqrt(input) + 1;   //to end the loop
        }
        else{
            prime = true;
        }
    }
    return prime;
}

//==============================================================================
// [Description]
// Prints the primes of an array.
// [Params]
// int arr[]: The array to find the primes of
// int length: the length of the array
// [Returns]
// Nothing
//==============================================================================
void isItPrime(int arr[], int length){
    if (length > 1){
        isItPrime(arr, length - 1);
    }

    bool prime = isPrime(arr[length - 1]);

    cout << "The number " << arr[length - 1] << " is ";

    if (prime){
        cout << "Prime" << endl;
    }
    else {
        cout << "Not Prime" << endl;
    }
}
