class Solution {

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }    
};

public:
    // sort, O(NlogN)time, no space, 51.77%, ok
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        return nums[k - 1];
    }
    
    // priority queue, O(NlogK)time, O(K) space, 72.12%, ok
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k) return -1;
        priority_queue<int, vector<int>, cmp> pq;
        for(auto n: nums){
            pq.push(n);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
    
    
};