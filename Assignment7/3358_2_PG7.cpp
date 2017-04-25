// Author Names: Rafael Reza-36 & Cullen Sturdivant-48
// Due Date: 04/26/2017
// Programming Assignment 7
// Spring 2017 - CS  3358 - Section Number: 2
// Instructor : Husain Gholoom
//
// Hashing and dashing and prancing

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hashtable {

public:
    int Hash(string key);

};

int Hashtable::Hash(string key){

    int index;
    int hash = 0;

    index = key.length();

    return index;
}
//just wrote this real quick to test out the simple hash function
int main()
{
    int index;

    Hashtable hashObj;

    index = hashObj.Hash("DeezNutz");
    cout << "index = " << index << endl;
}
