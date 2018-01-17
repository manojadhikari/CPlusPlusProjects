//Zach Bellay and Manoj Adhikari
//COEN 70 Lab 3
//Written: 10/04/16
// FILE: sequence.cpp
//Description: Implementation file of sequence class
//See sequence.h for documentation

#include "sequence.h"

using namespace coen70_lab3;

//MODIFICATION MEMBER FUNCTIONS
void sequence::start(){
    current_index = 0;
}

void sequence::advance(){
    
    if(current_index < used)
        current_index++;
}

void sequence::insert(const value_type& entry){
    //Shift array to the right
    
    for(int i = used; i > current_index; i--)
        data[i] = data[i-1];
    
    data[current_index] = entry;
    ++used;
}

void sequence::attach(const value_type& entry){
    //Shift array to the right
    
    for(int i = used; i > current_index+1; i--)
        data[i] = data[i-1];
    
    if(!is_item())
        data[current_index]=entry;
    else
        data[++current_index]=entry;
    
    ++used;
}

void sequence::remove_current(){
    //Shift the array to left until the value at current index is replaced
    for(int i=current_index;i<used;i++){
        data[i]=data[i+1];
    }
}

void sequence::insert_front(const value_type& entry){
    //shift the array to the right to make room at index 0 so that you can insert at the front
    current_index = 0;
    
    for(int i = used; i > current_index; i--)
        data[i] = data[i-1];
    
    data[current_index] = entry;
    ++used;
}

void sequence::remove_front(){
    //shift the array left losing the value on the first index; Also decrease used value.
    
    for(int i=0;i<used;i++)
        data[i]=data[i+1];
        
    --used;
}

void sequence::attach_back(const value_type& entry){
    //Insert the new value at the end of sequence
    data[used] = entry;
    current_index = used;
    ++used;
}

void sequence::end(){
    //make current to the last value we have
    current_index = used - 1;
}

void sequence::operator +=(const sequence& addend){
    //Take the array in addend and attach it to the end of the array in this sequence
    
    for(int i = 0; i < addend.used; ++i)
        data[used+i] = addend.data[i];
    
}

sequence::size_type sequence::size() const{
    //size()==the used value
    return used;
}

bool sequence::is_item() const{
    //if current index is less than used it returns true
    return current_index < used;
}

sequence::value_type sequence::current() const{
    return data[current_index];
}

sequence::value_type sequence::operator [](size_type index) const{
    
    assert(index < used && index >= 0);
    return data[index];
}

sequence operator +(const sequence& s1, const sequence& s2){
    sequence s3;
    
    //Add all of s1 to s3
    for(int i = 0; i < s1.size(); ++i)
        s3.attach_back(s1[i]);
    
    //Add all of s2 to s3
    for(int j = 0; j < s2.size(); j++)
        s3.attach_back(s2[j]);
    
    return s3;
}



