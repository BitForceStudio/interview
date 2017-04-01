/****************************************************************************************************
                                   284. Peeking Iterator        
-----------------------------------------------------------------------------------------------------
Given an Iterator class interface with methods: next() and hasNext(), design and implement a 
PeekingIterator that support the peek() operation -- it essentially peek() at the element that will 
be returned by the next call to next().

Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.

Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.

You call next() the final time and it returns 3, the last element. Calling hasNext() after that 
should return false.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	// Below is the interface for Iterator, which is already defined for you.
	// **DO NOT** modify the interface for Iterator.
	class Iterator {
	    struct Data;
		Data* data;
	public:
		Iterator(const vector<int>& nums);
		Iterator(const Iterator& iter);
		virtual ~Iterator();
		// Returns the next element in the iteration.
		int next();
		// Returns true if the iteration has more elements.
		bool hasNext() const;
	};


	class PeekingIterator : public Iterator {
	private:
	    int peekval;
	    bool qpeek;
	public:
		PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		    // Initialize any member here.
		    // **DO NOT** save a copy of nums and manipulate it directly.
		    // You should only use the Iterator interface methods.
		}

	    // Returns the next element in the iteration without advancing the iterator.
		int peek() {
		    if (qpeek) 
		    {
		        return peekval;
		    }
		    
	        if (Iterator::hasNext())
	        {
	            peekval = Iterator::next();
	            qpeek = true;
	            return peekval;
	        }
	        return NULL;
		}

		// hasNext() and next() should behave the same as in the Iterator interface.
		// Override them if needed.
		int next() {
		    if (qpeek)
		    {
		        qpeek=false;
		        return peekval;
		    }
		    else
		    {
		        if(Iterator::hasNext())
		        {
		            return Iterator::next();
		        }
		    }
		    return NULL;
		}

		bool hasNext() const {
		    if (qpeek)
		    {
		        return true;
		    }
		    else
		    {
		        return Iterator::hasNext();
		    }
		}
	};

}

/****************************************************************************************************
                                             Note
The idea is to store the peek and if has stored peek, then return it. 
However, there is a better solution:
class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
    }

    int peek()
    {
        return Iterator(*this).next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};
I think it constract a new iterator and return the next....

****************************************************************************************************/