//Robbie Culkin, Manoj Adhikari
//Random Generator
//Coen 70, Lab 2
//9-27-2016


//Define a class random with private variables and public member functions to modify the variables
class RandGen{
    int seed;
    int multiplier;
    int increment;
    int modulus;
public:
    //Postcondition: initializes all the variables
    RandGen(int seed,int multiplier, int increment, int modulus);
    //Postcondition: seed equals the random number generated
    int next();
    //Postcondition: seed equals user's input
    void setSeed(int new_seed);
};
