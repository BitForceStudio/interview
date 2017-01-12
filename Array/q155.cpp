/****************************************************************************************************
                                     155. Min Stack        
-----------------------------------------------------------------------------------------------------
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
****************************************************************************************************/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stack.push_back(x);
        if (minstack.empty() || x<=minstack.back()) minstack.push_back(x);  // *
    }
    
    void pop() {
        if (minstack.back()==stack.back())
            minstack.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
private:
    vector<int> stack;
    vector<int> minstack;
};


// faster solution, using self-defined structure with current min value. 
class MinStack {
public:
    /** initialize your data structure here. */
    struct minStruct{
        int val;
        int min;
    };
    MinStack() {
    }
    
    void push(int x) {
        minStruct curr;
        curr.val=x;
        if (stack.empty() || currMin>x) {curr.min=x; currMin=x;}
        else curr.min=currMin;
        stack.push_back(curr);
    }
    
    void pop() {
        stack.pop_back();
        currMin=stack.back().min;
    }
    
    int top() {
        return stack.back().val;
    }
    
    int getMin() {
        return currMin;
    }
private:
    vector<minStruct> stack;
    int currMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

/****************************************************************************************************
                                             Note
two stacks
* need to be careful about equals. 

there is another solution, linked list, or structure:

struct minStruct {
	int val;
	int min;
}
****************************************************************************************************/