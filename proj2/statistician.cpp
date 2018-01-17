// Robbie Culkin
// Manoj Adhikari
//  
//  statistician.cpp
//  9/27/16
//
//

#include "statistician.hpp"

statistician::statistician()
{
    _length = 0;
    _sum = 0;
    _flag = false; //used to determine if any values have been added to the sequence yet
}

void statistician::next_number(double number)
{
    _length++;
    _last = number;
    _sum += number;
    
    //if this is the first number, it is by default the smallest
    //if it is smaller than the smallest number, it is the new smallest number
    if (number < _smallest || _flag == false)
    {
        _smallest = number;
    }
    
    //if this is the first number, it is by default the largest
    //if it is larger than the largest number, it is the new largest number
    if (number > _largest || _flag == false)
    {
        _largest = number;
    }
    
    _flag = true;
}

int statistician::length()
{
    return _length;
}

double statistician::last()
{
    //check that at least one number has been added to the sequence
    assert(_flag == true);
    return _last;
}

double statistician::sum()
{
    return _sum;
}

double statistician::mean()
{
    //check that at least one number has been added to the sequence
    assert(_flag == true);
    return sum()/length();
}

double statistician::smallest()
{
    //check that at least one number has been added to the sequence
    assert(_flag == true);
    return _smallest;
}

double statistician::largest()
{
    //check that at least one number has been added to the sequence
    assert(_flag == true);
    return _largest;
}

void statistician::erase()
{
    //check that at least one number has been added to the sequence
    assert(_flag == true);
    
    _length = 0;
    _sum = 0;
    _flag = false;
}

statistician statistician::operator+ (const statistician& s2)
{
    statistician s3;
    s3._flag = this->_flag || s2._flag;
    s3._length = this->_length + s2._length;
    s3._last = s2._last;
    s3._sum = this->_sum + s2._sum;
    
    //take the smaller "smallest" value of the two objects being added
    if(this->_smallest < s2._smallest)
        s3._smallest = this->_smallest;
    else s3._smallest = s2._smallest;
    
    //take the bigger "largest" value of the two objects being added
    if(this->_largest > s2._largest)
        s3._largest = this->_largest;
    else s3._largest = s2._largest;
    
    return s3;
}

statistician statistician::operator= (const statistician& s2)
{
    this->_flag = s2._flag;
    this->_length = s2._length;
    this->_last = s2._last;
    this->_sum = s2._sum;
    this->_smallest = s2._smallest;
    this->_largest = s2._largest;
    
    return *this;
}