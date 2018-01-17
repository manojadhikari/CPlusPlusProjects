// FILE: node.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.


//Jacob Asa, Riley Bergin, Manoj Adhikari
//Coen 70, Lab 7

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen70_lab7
{
    
    //This function returns the number of nodes in the linked list
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        size_t answer;
        answer = 0;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;

        return answer;
    }
    
    
    //list_head_insert, This function adds a new node containing the given entry at the head of the linked list.
    //The head_ptr points to the head of the new, longer list.
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
        node* new_node;
        new_node = new node (entry, head_ptr);
        if(head_ptr == NULL)
            head_ptr = new_node;
        else{
            new_node->set_link(head_ptr);
            head_ptr = new_node;
        }
            
    	//Original:: head_ptr = new node(entry, head_ptr);
    }
    
    

    // A new node containing the given entry has been added
    // after the node that previous_ptr points to.
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
        assert(previous_ptr != NULL);//Added
        
    	node *insert_ptr;
    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }
    
    //     The pointer returned points to the first node containing
    //     the specified target in its data member. If there is no such node, the
    //     null pointer is returned.
    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    //This is the constant version of the list_search function. The only difference is that it returns a const node*.
    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    
    //The pointer is returned which points to the specified position in the list. If the position doesn't exist,
    //The null pointer is returned.
    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    //This is a list_locate function which does the exact same this as the function above
    //However, it returns a const node* to the specified position.
    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    
    //This function removes the node after previous_ptr from the linked list
    void list_head_remove(node*& head_ptr)
    {
        
        assert(head_ptr!=NULL);//added
        
    	node *remove_ptr;
    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    //This function removes the node after the previous_ptr from from linked list.
    void list_remove(node* previous_ptr)
    {
        assert(previous_ptr!=NULL && previous_ptr->link()!=NULL); //Added
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    //All the nodes of the linked list are freed and then the memory is returned to the heap
    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    
    //A new copy of the linked list is made such that head_ptr and
    //tail_ptr point to to its head and tail
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    // A new list is created starting from start_ptr upto but not including end_ptr.
    // head_ptr and tail_ptr point to the beginning and end of this new list.
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr)
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        
        // Handle the case of the empty list.
        if(start_ptr == NULL)
            return;
        
//        if (list_length(start_ptr) < 2)
//            return;
        
        node *temp = start_ptr;
        
        list_head_insert(head_ptr, temp->data());
        temp = temp->link();
        
        for (size_t i = 2; temp != end_ptr; i++)
        {
            list_insert_at(head_ptr,temp->data(),i);
            tail_ptr = temp;
            temp = temp->link();
            
        }
    }
    

    // This function counts and returns the number of nodes that contain the value equal to the target.
    size_t list_occurrences(node* head_ptr, const node::value_type& target)
    {
        size_t count = 0;
        
        node* cursor = head_ptr;
        while(cursor->link() != NULL){
        
            if(cursor->data() == target)
                ++count;
            cursor = cursor->link();
        }

        return count;
    }

    
    // A new node is added at the specified position in the list. It contains entry as the data.
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position)
    {
        assert(position > 0 && position <= list_length(head_ptr)+1);
        
        if(head_ptr == NULL || position == 1 ){
            list_head_insert(head_ptr,entry);
            return;
        }

//        node* cursor = head_ptr;
//        //loop through list to desired position
//        for(int i = 1; i < position - 1; ++i){
//        
//            cursor = cursor->link();
//        }
        list_insert(list_locate(head_ptr, position - 1), entry);
    }
    
    

    //This function removes a node at the specified position and returns the data contained in that node.
    node::value_type list_remove_at(node*& head_ptr, size_t position)
    {
        assert(position>0 && position<=list_length(head_ptr));
        node* cursor = head_ptr;
        //loop through list to desired position
        for(int i=1; i<position; ++i){
            
            cursor=cursor->link();
        }
        node::value_type data = cursor->data();
        list_remove(cursor);

        return data;
    }

    //This function copies the items from the start position to the finish position in the list that
    //head_ptr points to. The value returned is the head pointer to the copied segment.
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    {
        assert(1 <= start && start <= finish && finish <= list_length(head_ptr));
        
        node* newHead = new node;
        node* newTail = new node;
        
        list_piece(list_locate(head_ptr, start), list_locate(head_ptr, finish+1), newHead, newTail);

        return newHead;
    }
}


