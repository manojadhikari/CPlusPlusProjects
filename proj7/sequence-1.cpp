//Asa Jacob, Riley Bergin, Manoj Adhikari
//Coen 70, Lab 7
//sequence.cpp

//Invariants:
    //1. Many nodes equals the number of nodes in the sequence
    //2. 


#include <stdio.h>
#include <cassert>
#include <iostream>
#include "sequence.h"

using namespace std;

namespace coen70_lab7
{
    
    //This is a constructor and here we initialize our sequence as an empty sequence
    sequence::sequence( )
    {
        node *head_ptr = NULL;
        node *tail_ptr = NULL;
        node *cursor = NULL;
        node *precursor = NULL;
        size_type many_nodes = 0;
    }
    
    //This is our copy constructor and we set the pointer of this sequence to the source
    sequence::sequence(const sequence& source)
    {
        *this = source;
    }
    
    //This is a destructor which is used to remove all the nodes in the sequence
    sequence::~sequence( )
    {
        start();
        while(head_ptr!=NULL)
            remove_current();
    }

    //The first item in the sequence becomes the current item  if the list is not empty.
    void sequence::start( )
    {
        if(many_nodes != 0)
        {
            precursor = NULL;
            cursor = head_ptr;
        }
    }
    
    //The last item becomes the current item and the precursor points to the node before.
    void sequence::end()
    {
        if(many_nodes != 0)
        {
            cursor = head_ptr;
            while(cursor != tail_ptr)
                advance();
        }
    }
    
    //If the current item was already the last item in the sequence, then there is no longer any current item.
    //Otherwise, the new current item is the item immediately after the original current item.
    void sequence::advance( )
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    
    
    //A new copy of entry has been inserted in the sequence before the current item.
    // If there was no current item, then the new entry has been inserted at the front of the sequence.
    //In either case, the newly inserted item is now the current item of the sequence.
    void sequence::insert(const value_type& entry)
    {
        node *new_node = new node(entry);
        new_node->set_link(cursor);
        
        // Handling case for inserting into an empty list
        if(head_ptr == NULL)
        {
            head_ptr->set_link(new_node);
            tail_ptr->set_link(new_node);
        }
        // Handling inserting at the beginning
        else if(precursor == NULL)
        {
            head_ptr = new_node;
        }
        //Handling inserting at the end
        else if(cursor == NULL)
        {
            tail_ptr = new_node;
            precursor->set_link(new_node);
        }
        else
        {
            precursor->set_link(new_node);
        }
        
        
        cursor=new_node;
        ++many_nodes;
    }
    
    //A new copy of entry has been attached in the sequence after the current item.
    // If there was no current item, then the new entry has been inserted at the current item.
    //In either case, the newly attached item is now the current item of the sequence.
    
    void sequence::attach(const value_type& entry)
    {
        cout << "test1";
        node *new_node = new node(entry);
        // Handling case for attaching to an empty list
        if(head_ptr == NULL)
        {
            head_ptr->set_link(new_node);
            tail_ptr->set_link(new_node);
        }
        //Handling attaching at the end
        else if(cursor == NULL)
        {
            tail_ptr = new_node;
            precursor->set_link(new_node);
        }
        else
        {
            new_node->set_link(cursor->link());
            cursor->set_link(new_node);
            

        }
        
        
        cursor=new_node;
        ++many_nodes;
    }
    
    
    //This is an assignment operator and it copies the sequence from the source into this sequence
    void sequence::operator =(const sequence& source)
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        
        //Handling case of an empty list
        if (source.head_ptr == NULL)
            return;
        
        // Handling case of a list of size one
        if (source.head_ptr->link() == NULL)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            start();
        }
        
        list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
        list_piece(source.cursor, NULL, cursor, tail_ptr);
        precursor->set_link(cursor);
    }
    
    //The current item has been removed from the sequence, and the item after this (if there is one) is now the new current item.
    void sequence::remove_current( )
    {
        assert(is_item());
        precursor->set_link(cursor->link());
        node* temp = cursor;
        cursor = cursor->link();
        delete temp;
        --many_nodes;
    }

    sequence::size_type sequence::size( ) const
    {
        return many_nodes;
    }
    
    //This function returns true if the current item points to a valid node, i.e. a node that is not NULL.
    bool sequence::is_item( ) const
    {
        if(cursor!=NULL)
            return true;
        return false;
    }
    
    
    //This functions returns the data in the current node if it is not null.
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return cursor->data();
    }
}
