/****************************************************************************************************
                                  225. Implement Stack using Queues     
-----------------------------------------------------------------------------------------------------
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, 
size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a 
list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on 
an empty stack).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Stack {
	public:
	    // Push element x onto stack.
	    void push(int x) {
	        qtmp.push(x);
	        swap();
	    }

	    // Removes the element on top of the stack.
	    void pop() {
	        stack.pop();
	    }

	    // Get the top element.
	    int top() {
	        if(stack.empty()) return NULL;
	        return stack.front();
	    }

	    // Return whether the stack is empty.
	    bool empty() {
	        return stack.empty();
	    }
	private:
	    queue<int> qtmp;
	    queue<int> stack;
	    
	    void swap()
	    {
	        while(!stack.empty())
	        {
	            qtmp.push(stack.front());
	            stack.pop();
	        }
	        while(!qtmp.empty())
	        {
	            stack.push(qtmp.front());
	            qtmp.pop();
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
two queues. no trick. 
****************************************************************************************************/