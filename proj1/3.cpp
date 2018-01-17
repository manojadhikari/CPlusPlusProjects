// Vineet Joshi, Manoj Adhikari
// September 20, 2016
// 3.cpp
// This is the third part of Lab 1 of COEN 70, which displays all words from input file with length of at least 10 characters.

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Invalid Arguments.";
    } else {
        ifstream myFile (argv[1]);
        
        cout << endl;
        
        string line, word, newWord;
        if (myFile.is_open()) {
            // while a line can be read from the file:
            while (getline(myFile, line)) {
                istringstream iss(line);
                string word;
                // while a word can be picked from the line:
                while (iss >> word) {
                    newWord = "";
                    
                    // loops through each character of the word
                    for (int i = 0; i < word.length(); i++) {
                        int asciiVal = (int)(word.at(i));
                        if (asciiVal >= 65 && asciiVal <= 90) {
                            // if the character is uppercase, it is transferred to string 'newWord'
                            newWord += (char)(asciiVal);
                        } else if (asciiVal >= 97 && asciiVal <= 122) {
                            // if the character is lowercase, its uppercase version is transferred to string 'newWord'
                            asciiVal -= 32;
                            newWord += (char)(asciiVal);
                        }
                    }
                    
                    // if the string 'newWord' has length of at least 10 characters:
                    if (newWord.length() >= 10) {
                        cout << newWord;
                        cout << endl;
                    }
                }
            }
        }
        
        // closes the file!!
        myFile.close();
    }
    
    cout << endl;
    
    return 0;
}