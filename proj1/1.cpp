// Vineet Joshi, Manoj Adhikari
// September 20, 2016
// 1.cpp
// This is the first part of Lab 1 of COEN 70, which displays a pattern of numbers.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // loops from 10 to 20 for the setw function:
    for (int i = 10; i < 20; i++) {
        std::cout << std::setw(i);
        if (i%2 == 0) {
            // if i is even, then print out '0123456789'
            for (int k = 0; k < 10; k++) {
                std::cout << k;
            }
        } else {
            // if i is odd, then print out '9876543210'
            for (int k = 9; k >= 0; k--) {
                std::cout << k;
            }
        }
        
        std::cout << endl;
    }
    
    std::cout << endl;
    
    return 0;
}