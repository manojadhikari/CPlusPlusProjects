//Zach Bellay and Manoj Adhikari
//COEN 70 Lab 3
//Written: 10/04/16
// FILE: sequence.h
// CLASS PROVIDED: sequence (part of the namespace coen70_lab3)
// There is no implementation file provided for this class since it is
// an exercise from Section 3.2 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type CAPACITY = _____
//     sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
//   void insert_front(const value_type& entry)
//      Precondition: size() < CAPACITY
//      Postcondition: The new item has been inserted at the front of the sequence and is now the current item.
//
//   void remove_front()
//      Precondition: There at least one item in the sequence.
//      Postcondition: The item from the front is removed. The new front item is now the current item.
//
//  void attach_back(const value_type& entry)
//      Precondition: size()  < CAPACITY
//      Postcondition: The item has been inserted at the back of the sequence and is now the current item.
//
//  void end()
//      Precondition: There is at least one item in the sequence.
//      Postcondition: The last item is now the current item.
//
//  void operator +=(const sequence& addend)
//      Precondition: size of sequence += addend must be less than CAPACITY
//      Postcondition: sequence now has appended all of the numbers in the addend to the end of sequence
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
//   value_type operator [](size_type index) const
//      Precondition: size() > 0
//      Postcondition: returns the value of a sequence at an index
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
//  sequence operator+(const sequence& s1, const sequence& s2);
//      Precondition: The size of s1+s2 < CAPACITY
//      Postcondition: s1 will be appended with all of the items in s2

#ifndef MAIN_SEQUENCE_H
#define MAIN_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include <cassert>  //Provides assert()

namespace coen70_lab3
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 30;
        // CONSTRUCTOR
        sequence(){
            used = 0;
            current_index = 0;
        }
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void insert_front(const value_type& entry);
        void remove_front();
        void attach_back(const value_type& entry);
        void end();
        void operator +=(const sequence& addend);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
        value_type operator [](size_type index) const;
    private:
        value_type data[CAPACITY];
        size_type used;
        size_type current_index;
    };
    
    sequence operator +(const sequence& s1, const sequence& s2);
    
}

#endif
