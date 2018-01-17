// Vineet Joshi, Manoj Adhikari
// September 20, 2016
// 4.cpp
// This is the fourth part of Lab 1 of COEN 70, which fixes the given code so the B 'object' has string "Hello World".

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// initializes a struct 'object' that stores a string pointer:
struct object {
    string* s;
};

int main(int argc, char *argv[]) {
    object A, B;
    A.s = new string;
    // initializes string*s to a new string for the B 'object'
    B.s = new string;
    *A.s = "Hello World"; // A has "Hello World"
    *B.s = *A.s;                // B has "Hello World"
    *A.s = "Goodbye";     // A has "Goodbye"
    cout << *A.s << endl;
    cout << *B.s << endl;
    
    return 0;
}