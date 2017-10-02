/****************************************************************************************************
                                  347. Top K Frequent Elements           
-----------------------------------------------------------------------------------------------------
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    static bool compare(pair<int,int>& a, pair<int,int>& b) { return a.second>b.second; }
	    vector<int> topKFrequent(vector<int>& nums, int k) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len<=1) return nums;
	        
	        unordered_map<int,int> counter;
	        
	        for(int i=0;i<len;i++)
	        {
	            counter[nums[i]]++;
	        }
	        vector<pair<int,int> > ct;
	        for(unordered_map<int,int>::iterator it=counter.begin();it!=counter.end();++it)
	        {
	            pair<int,int> tmp;
	            tmp.first = it->first;
	            tmp.second = it->second;
	            ct.push_back(tmp);
	        }
	        
	        sort(ct.begin(),ct.end(),compare);
	        
	        for(int i=0;i<k;i++)
	        {
	            rst.push_back(ct[i].first);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
map, pair and then sort. it could be better if use the quick sort technice. 
Here is other's

****************************************************************************************************/

public List<Integer> topKFrequent(int[] nums, int k) {

	List<Integer>[] bucket = new List[nums.length + 1];
	Map<Integer, Integer> frequencyMap = new HashMap<Integer, Integer>();

	for (int n : nums) {
		frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
	}

	for (int key : frequencyMap.keySet()) {
		int frequency = frequencyMap.get(key);
		if (bucket[frequency] == null) {
			bucket[frequency] = new ArrayList<>();
		}
		bucket[frequency].add(key);
	}

	List<Integer> res = new ArrayList<>();

	for (int pos = bucket.length - 1; pos >= 0 && res.size() < k; pos--) {
		if (bucket[pos] != null) {
			res.addAll(bucket[pos]);
		}
	}
	return res;
}

// maxheap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};