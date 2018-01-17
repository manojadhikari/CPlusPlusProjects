//James Olivas, Manoj Adhikari
//Coen 70, Lab 5
//10-18-2016

#include "mystring.h"
#include <cassert>
#include <string.h>

//Invariants: 1. current_length can never be greater than allocated
            //2. current_length equals the number of characters in the string pointed by the *sequence.
                //This length includes the Null string terminator.
            //3. Current_length is always >=1, if the sequence points to a string or an empty string



namespace coen70_lab5{
    
    //CONSTRUCTOR for the string class
    //default argument is the empty string
    //The CONSTRUCTOR makes sure that the string contains the sequence of chars from str if str is a Null terminated string
    string::string(const char str[ ]){
        current_length = strlen(str);
        allocated = current_length + 1;
        
        //Set the sequence to NULL to distinguish the call on reserve() from constructor and copy constructor and other functions
        sequence=NULL;
        reserve(allocated);
        strncpy(sequence,str,allocated);
    }
    

    //Copy constructor, it copies the sequence from a source into the current sequence.
    string::string(const string& source){
    
        allocated = source.allocated;
        current_length = source.current_length;
        sequence=NULL;
        
        reserve(current_length);
        strncpy(sequence, source.sequence,allocated);
        
    }
    

    //Destructor, Destroys the current sequence
    string::~string( ){
        delete[] sequence;
    }
    
    //Reserve functions allocates extra needed space so that all other functions can now
    //work efficiently without allocating new memory untill there are n characters in the string
    void string::reserve(size_t n){
        char c;
        char *larger_sequence;
    
        //n<allocated-1 means that we already have enough space
        if(n==allocated-1){
            return;
        }
        
        //we can't allocate less that what we are already using
        if(n<current_length+1){
            n=current_length+1;
        }
        
        larger_sequence = new char[n];
        
        //if reserve was not called from the constructor or copy constructor
        //only then the sequence will have something to copy to the larger_sequence
        if(sequence!=NULL)
            strncpy(larger_sequence,sequence,n);
        
        //if reserve was called from the constructor or copy constructor
        //we delete the sequence so that we can assign it to the larger sequence
        if(sequence==NULL){
            delete[] sequence;
        }
        
        //Update the sequence and allocated
        sequence = larger_sequence;
        allocated = n;
    }
    
    
    //This function returns the value value at the specified position of the string.
    char string::operator [ ](size_t position) const{
        assert(position<length());
        return sequence[position];
    }
   
    //This function catenates addend to the end of the string
    void string::operator +=(const string& addend){
        
        //if catenation requires more space, call reserve passing the space required
        if (current_length + addend.current_length > allocated -1)
            reserve(current_length+addend.current_length);
        
        strncat(sequence, addend.sequence, addend.current_length);
        current_length = strlen(sequence);
    }
    
    //The function is triggered if an ordinary null terminated string is to be added to the end of the string
    void string::operator +=(const char addend[ ]){
        
        //if catenation requires more space, call reserve passing the space required
        if (current_length + strlen(addend) > allocated -1)
            reserve(current_length+strlen(addend));
        

        strncat(sequence, addend, strlen(addend));
        current_length = strlen(sequence);
    }
    
    //This function catenates a single character addend to the end of the sequence
    void string::operator +=(char addend){
        
        //if catenation requires more space, reserve is called
        if(current_length+1 > allocated-1)
            reserve(allocated+1);
        
        sequence[current_length]=addend;
        ++current_length;
        //add null character at the end
        sequence[current_length]= '\0';
        
    }
    
    
    //A string is returned which is the catenation of s1 and s2.
    string operator +(const string& s1, const string& s2){
        string s3;
        s3+=s1;
        s3+=s2;
        return s3;
    }
    
    //A string is read from the istream ins, and then returned by the function
    //The reading operation skips white space at teh start of ins.
    //Then the string is read up to the next white space or the end of the file.
    //Null character which is also a white space is not read
    std::istream& operator >>(std::istream& ins, string& target){
        char c;
        //ignore all the white space
        while(ins && isspace(ins.peek()))
            ins.ignore();
        
        target = "";
        while (ins && !isspace(ins.peek())){
            
            ins>>c;
            
            //call the operator += to concatanate each character until the next which space
            target+=c;
        }
        
        return ins;

        
    }
    
    //This function writes the sequence of characters in source to the outs.
    //Then, outs is returned
    std::ostream& operator <<(std::ostream& outs, const string& source){
        outs<<source.sequence;
        return outs;
    }
    
    //This function is a string assignment which assign the sequence to the sequence of the source
    //by compeletely deleting the first sequence.
    //Finally it returns the pointer to the sequence
    
    string& string::operator =(const string& source){
        char *new_sequence;
        
        //if more space is required to copy the string of the source
        if (allocated <= source.allocated)
        {
            new_sequence = new char[source.allocated];
            delete [] sequence;
            sequence = new_sequence;
            allocated = source.allocated;
        }
        
        strncpy(sequence, source.sequence,source.current_length);
        current_length = strlen(source.sequence);
        return *this;
    }
    
    //    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
    //    for the string class, forming a total order semantics, using the usual
    //    lexicographic order on strings.
    
    //Checks to see if two strings are equal
    bool operator ==(const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) == 0)
            return true;
        return false;
    }
    
    //Returns true if two strings are not equal
    bool operator !=(const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) != 0)
            return true;
        return false;
    }
    
    //Returns true if the string on s1 is greater than string on s2
    bool operator > (const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) > 0)
            return true;
        return false;
    }
    
    //Returns true if the string on s1 is less than string on s2
    bool operator < (const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) < 0)
            return true;
        return false;
    }
    
    //Returns true if the string on s1 is greater than or equal to the string on s2
    bool operator >=(const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) >= 0)
            return true;
        return false;
    }
    
    //Returns true if the string on s1 is less than or equal to the string on s2
    bool operator <=(const string& s1, const string& s2){
        if (strcmp(s1.sequence, s2.sequence) <= 0)
            return true;
        return false;
    }  
    
    
    
}

