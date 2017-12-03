/****************************************************************************************************
                                      146. LRU Cache       
-----------------------------------------------------------------------------------------------------
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the 
following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, 
otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached 
its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class LRUCache {
	private:
	    struct DoubleLinkedList{
	        int val;
	        int key;
	        DoubleLinkedList* left;
	        DoubleLinkedList* right;
	        DoubleLinkedList(int x,int y) : val(x), key(y),left(NULL),right(NULL) {}
	    };
	    
	    DoubleLinkedList* head;
	    DoubleLinkedList* tail;
	    
	    unordered_map<int,DoubleLinkedList*> m;
	    int c=0;
	    int counter=0;
	public:
	    LRUCache(int capacity) {
	        c = capacity;
	        head = new DoubleLinkedList(0,0);
	        tail = new DoubleLinkedList(0,0);
	        head->right=tail;
	        tail->left = head;
	    }
	    
	    int get(int key) {
	        if(m.find(key)==m.end()) return -1;
	        DoubleLinkedList* curr = m[key];
	        DoubleLinkedList* left = curr->left;
	        DoubleLinkedList* right = curr->right;
	        left->right = right;
	        right->left = left;
	        
	        curr->right = head->right;
	        head->right->left = curr;
	        head->right = curr;
	        curr->left = head;
	        return curr->val;
	    }
	    
	    void put(int key, int value) {
	        if(m.find(key)!=m.end())
	        {
	            m[key]->val = value;
	            get(key);   // ***
	            return;
	        }
	        else if (counter==c)
	        {
	            DoubleLinkedList* lru = tail->left;
	            lru->left->right = tail;
	            tail->left = lru->left;
	            m.erase(m.find(lru->key));
	            delete(lru);
	            counter--;
	        }
	        
	        DoubleLinkedList* added = new DoubleLinkedList(value,key);
	        m[key] = added;
	        added->right = head->right;
	        head->right->left = added;
	        head->right = added;
	        added->left = head;
	        counter++;
	    }
	};

	/**
	 * Your LRUCache object will be instantiated and called as such:
	 * LRUCache obj = new LRUCache(capacity);
	 * int param_1 = obj.get(key);
	 * obj.put(key,value);
	 */

}

/****************************************************************************************************
                                             Note
*** need to update this updated one.
****************************************************************************************************/