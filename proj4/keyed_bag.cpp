// keyed_bag.cpp
// Thomas King and Manoj Adhikari
// 2016-10-11
// Implementation for a keyed bag
//
// Invariants:
// 	the number of items in keys and data must be equal to used

#include <cassert>
#include "keyed_bag.h"

namespace coen70_lab4
{
   /*
    Traverse through the bag to see if the key is in the bag.
    If key was in the keyed_bag, then the key and its value have been removed;
    otherwise the keyed_bag is unchanged. A true return value indicates that an
    item was removed; false indicates that nothing was removed.
    */
    bool keyed_bag::erase(const key_type& key)
	{
		for (size_type i = 0; i < used; ++i)
		{
			if (keys[i] == key)
			{
				for (size_type j = i; j < used - 1; ++j)
				{
					keys[j] = keys[j + 1];
					data[j] = data[j + 1];
				}
				--used;
				return true;
			}
		}
		return false;
	}
    
    //Adds a new copy of entry to the keyed_bag with the corresponding key.
    //Inserted at the end
	void keyed_bag::insert(const value_type& entry, const key_type& key)
	{
		assert(size() < CAPACITY);
		
		if(!has_key(key))
		{
			data[used] = entry;
			keys[used] = key;
			++used;
		}
	}

    //Each item and its key in addend is added to this keyed_bag.
    void keyed_bag::operator +=(const keyed_bag& addend)
	{
		assert(size() + addend.size() <= CAPACITY);

		for (size_type i = 0; i < addend.used; ++i)
		{
            //use insert function to add items to this bag
			insert(addend.data[i], addend.keys[i]);
		}
	}

    //Traverse to see if the bag has the matching key.
    //If the key matches, return true
    //Otherwise return false
	bool keyed_bag::has_key(const key_type& key) const
	{
		for (size_type i = 0; i < used; ++i)
		{
			if (keys[i] == key) return true;
		}

		return false;
	}

    //Finds and returns the data value corresponding to the given key
	keyed_bag::value_type keyed_bag::get(const key_type& key) const
	{
		assert(has_key(key));
		for (size_type i = 0; i < used; ++i)
		{
			if (keys[i] == key) return data[i];
		}
	}

    //First counts the total number of items in the keyed_bag.
    //Then returns the number
	keyed_bag::size_type keyed_bag::count(const value_type& target) const
	{
		size_type counter = 0;
		for (size_type i = 0; i < used; i++)
		{
			if (data[i] == target) ++counter;
		}

		return counter;	
	}

    //The keyed_bag returned is the union of b1 and b2.
	keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
	{
		assert(b1.size() + b2.size() <= keyed_bag::CAPACITY);

		// Initialize the new bag to hold the other 2
		keyed_bag new_bag;
		
		// Insert other bags
		new_bag += b1;
		new_bag += b2;

		return new_bag;
	}
}
