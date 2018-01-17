//Robbie Culkin, Manoj Adhikari
//Random Generator
//Coen 70, Lab 2
//9-27-2016

#include "random.h"

//Define the next function to calculate the seed using linear cogruence method
int RandGen::next(){
    seed = (multiplier * seed + increment)% modulus;
    return seed;
}

//Reset the seed value to the value entered by user
void RandGen::setSeed(int new_seed){
    seed = new_seed ;
}

//Constructor to set initialize the private member variables
RandGen::RandGen(int seed,int multiplier, int increment, int modulus){
    this->seed=seed;
    this->multiplier=multiplier;
    this->increment=increment;
    this->modulus=modulus;
}
