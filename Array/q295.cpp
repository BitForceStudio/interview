/****************************************************************************************************
                                295. Find Median from Data Stream      
-----------------------------------------------------------------------------------------------------
Median is the middle value in an ordered integer list. If the size of the list is even, there is no 
middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class MedianFinder {
	public:
	    /** initialize your data structure here. */
	    MedianFinder() {
	        head=new LinkedList(0);
	        nnode=0;
	        mid1=0;
	        mid2=0;
	    }
	    
	    void addNum(int num) {
	        LinkedList* dp=head;
	        nnode++;
	        int m1=(nnode%2==0)?(nnode/2-1):(nnode/2);
	        int m2=nnode/2;
	        int count=0;
	        while (dp!=NULL)
	        {
	            if (dp->next!=NULL && num>dp->next->val)
	            {
	                dp=dp->next;
	                if (count==m1) mid1=dp->val;
	                if (count==m2) mid2=dp->val;
	                count++;
	            }
	            else 
	            {
	                LinkedList* curr = new LinkedList(num);
	                curr->next=dp->next;
	                dp->next=curr;
	                dp=dp->next;
	                if (count==m1) mid1=dp->val;
	                if (count==m2) mid2=dp->val;
	                count++;
	                break;
	            }
	        }
	        
	        while(dp!=NULL && count<=m2)
	        {
	            dp=dp->next;
	            if (count==m1) mid1=dp->val;
	            if (count==m2)
	            {
	                mid2=dp->val;
	                break;
	            }
	            count++;
	        }
	    }
	    
	    double findMedian() {
	        return double((mid1+mid2))/2;
	    }
	    
	    struct LinkedList
	    {
	        int val;
	        LinkedList* next;
	        LinkedList(int x) : val(x), next(NULL) {}
	    };
	    
	private:
	    LinkedList* head;  // useless head;
	    int mid1;
	    int mid2;
	    int nnode;
	};


    // update solution
	class MedianFinder {
	private:
	    vector<int> arr;
	public:
	    /** initialize your data structure here. */
	    MedianFinder() {
	        arr.resize(0);
	    }
	    
	    void addNum(int num) {
	        if (arr.size()==0) arr.push_back(num);
	        else if (arr.size()==1)
	        {
	            if(num>arr[0]) arr.push_back(num);
	            else arr.insert(arr.begin(),num);
	        }
	        else
	        {
	            int st=0,ed=arr.size()-1;
	            int mid=0;
	            while(st<ed)
	            {
	                mid=(st+ed)/2;
	                if(arr[mid]<num) st=mid+1;
	                else if (arr[mid]>num) ed=mid;
	                else 
	                {
	                    st=mid;  //*
	                    break;
	                }
	            }
	            if (arr[st]<num) //**
	                arr.insert(arr.begin()+st+1,num);
	            else
	                arr.insert(arr.begin()+st,num);
	        }
	    }
	    
	    double findMedian() {
	        int len=arr.size();
	        if (len<1) return 0;
	        if (len%2==1) return arr[len/2];
	        else return (double(arr[len/2-1])+double(arr[len/2]))/2;
	    }
	};

	/**
	 * Your MedianFinder object will be instantiated and called as such:
	 * MedianFinder obj = new MedianFinder();
	 * obj.addNum(num);
	 * double param_2 = obj.findMedian();
	 */

}

/****************************************************************************************************
                                             Note
**** update my solution
keep a sorted array. using vector insert. 
* & ** is the place that for insert sort need to keep eye on.

**** heap
Better and passed solution: 
I keep two heaps (or priority queues):

Max-heap small has the smaller half of the numbers.
Min-heap large has the larger half of the numbers.
This gives me direct access to the one or two middle values (they're the tops of the heaps), so 
getting the median takes O(1) time. And adding a number takes O(log n) time.

Supporting both min- and max-heap is more or less cumbersome, depending on the language, so I simply 
negate the numbers in the heap in which I want the reverse of the default order. To prevent this 
from causing a bug with -231 (which negated is itself, when using 32-bit ints), I use integer types 
larger than 32 bits.

Using larger integer types also prevents an overflow error when taking the mean of the two middle 
numbers. I think almost all solutions posted previously have that bug.

C++

class MedianFinder {
    priority_queue<long> small, large;
public:

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};
****************************************************************************************************/