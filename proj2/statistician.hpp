// Robbie Culkin
// Manoj Adhikari
//
//  statistician.cpp
//  9/27/16
//
//

#ifndef statistican_hpp
#define statistican_hpp

#include <stdio.h>
#include <cassert>

#endif /* statistican_hpp */

class statistician
{
    bool _flag;
    int _length;
    double _last;
    double _sum;
    double _smallest;
    double _largest;
    
public:
    statistician();
    //Precondition: enter a decimal or integer value
    //Postcondition: value is added to the sequence
    void next_number(double number);
    
    //Precondition:
    //Postcondition: returns the number of values in the sequence
    int length();
    
    //Precondition: sequence must not be empty
    //Postcondition: returns the last value entered
    double last();
    
    //Precondition:
    //Postcondition: returns the sum of all values in the sequence
    double sum();
    
    //Precondition: sequence must not be empty
    //Postcondition: returns the mean of the values entered
    double mean();
    
    //Precondition: sequence must not be empty
    //Postcondition: returns the smallest value in the sequence
    double smallest();
    
    //Precondition: sequence must not be empty
    //Postcondition: returns the largest value in the sequence
    double largest();
    
    //Precondition:
    //Postcondition: resets the sequence
    void erase();
    
    //Precondition: parameters- two statistician objects
    //Postcondition: sum the two statitistician objects
    statistician operator+ (const statistician&);
    
    //Precondition: parameters- two statistician objects
    //Postcondition: copy the second statitistician object to the first
    statistician operator= (const statistician&);
};
