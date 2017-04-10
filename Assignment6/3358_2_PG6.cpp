// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 04/12/2017
// Programming Assignment 6
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Does shit that I haven't filled in yet

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

void printArr(int[], int);
int squares(int);
int powers(int, int);
int sumOfSquares(int);
void bubbleSort(int[], int);

int main()
{

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
    cout << "\t8. Determine if a number is prime (process all array values)\n";

    int input;
    int b = 2;

    cout << "Select from the following menu" << endl;
    cout << "A. Enter array size that is > 4." << endl
         << "X. Terminate the program. ";

    cin >> input;

    srand(time(0));
    int *arrSize;

    arrSize = new int [input];

    cout << endl;

    cout << "The generated array is: ";

    for(int i = 0; i < input; i++){
        arrSize[i] = (rand() % 20) + 1; //% 500) + 25; made nums smaller to check
        cout << arrSize[i] << " " ;
    }


    cout << endl << endl;

    int last = arrSize[input - 1];
    cout << "Table of square values 1 - ";
    cout << last << endl;

    int first = arrSize[0];

    cout << endl;

    cout << "Power Function: " << endl
         << first << " raised to the 2nd power is: " << powers(first,b) << endl;

    cout << endl;

    int poop = arrSize[input - 2];
    int sum = sumOfSquares(poop);

    cout << "Sum of squares between 0 and " << poop <<" is: " << sum << endl;


    cout << endl;


    delete[] arrSize;

}


int powers(int x, int y){

    if (y == 0)
        return (1);
    else if (y == 1)
        return (x);
    else{
        return (x * powers(x, y - 1));
    }
}

int sumOfSquares(int poop){

    if(poop == 1)
        return poop;
    else
        return (poop * poop + sumOfSquares(poop - 1));

}
// why you no work
void bubbleSort(int arr[], int input){

    if(input == 1)
        return ;
    else{
        for(int i = 0; i < input - 1; i++){
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
            }
        }
    bubbleSort(arr, input - 1);
}

//does not do poop
int squares(int num){
    if(num == 0)
        return 0;
    else{
            return num * squares(num);
        }
    }

/**void printArr(int arr[], int input){

    srand(time(0));
    int *a;

    a = new int [input];

    cout << "The generated array is: ";

    for(int i = 0; i < input; i++){
        a[i] = (rand() % 20) + 1; //% 500) + 25; made nums smaller to check
        cout << a[i] << " " ;
    }
}


        try {

            cout << "Select from the following menu" << endl;
            cout << "A. Enter array size that is > 4." << endl
                 << "X. Terminate the program. ";

            //cin >> choice;
            choice = getch();

            if(choice != 'A'){
                throw "*** Invalid Option ***";
            }
            else if(choice < 4){
                throw "*** Invalid Array Size Value ***";
            }

        }
               catch (const char* error) {
            cerr << "\nERROR: " << error << "\n"
                 << "Please choose a valid option." << endl;
        }
        }

    while(choice!= 'X');

   cout << "*** Program is terminated. Written by Rafael Reza "
         << "& Cullen Sturdivant ***" << endl;


    }
    ****/
