// Vineet Joshi, Manoj Adhikari
// September 20, 2016
// 2.cpp
// This is the second part of Lab 1 of COEN 70, which counts alphanumeric characters and non-alphanumeric characters.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string input;
    
    cout << "\n\nEnter a string to be counted -> ";
    std::getline(std::cin, input);
    
    std::cout << endl;
    
    int alphaNum = 0, notAlphaNum = 0;
    
    // loops through each character inside the input string
    for (int i = 0; i < input.length(); i++) {
        // stores the ASCII value of each character
        int asciiVal = (int)(input.at(i));
        if ((asciiVal >= 65 && asciiVal <= 90) || (asciiVal >= 97 && asciiVal <= 122)) {
            // if the character is uppercase or lowercase alphanumeric
            alphaNum++;
        } else if (asciiVal != 32) {
            notAlphaNum++;
        }
    }
    
    std::cout << "\""<< input << "\" has " << alphaNum << " alphanumeric characters and " << notAlphaNum << " non-alphanumeric characters.";
    
    std::cout << endl;
    
    return 0;
}