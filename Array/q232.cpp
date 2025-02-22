/****************************************************************************************************
                                 232. Implement Queue using Stacks        
-----------------------------------------------------------------------------------------------------
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, 
size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a 
list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called 
on an empty queue).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Queue {
	public:
	    // Push element x to the back of queue.
	    void push(int x) {
	        store(x);
	    }

	    // Removes the element from in front of queue.
	    void pop(void) {
	        queue.pop();
	    }

	    // Get the front element.
	    int peek(void) {
	        return queue.top();
	    }

	    // Return whether the queue is empty.
	    bool empty(void) {
	        return queue.empty();
	    }
	private:
	    stack<int> queue;
	    void store(int x)
	    {
	        stack<int> tmp;
	        while(!queue.empty())
	        {
	            tmp.push(queue.top());
	            queue.pop();
	        }
	        tmp.push(x);
	        while(!tmp.empty())
	        {
	            queue.push(tmp.top());
	            tmp.pop();
	        }
	        return;
	    }
	};

}

/****************************************************************************************************
                                             Note
clear your head. it is very easy.
****************************************************************************************************/