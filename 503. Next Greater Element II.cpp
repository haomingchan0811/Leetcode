class Solution {
public:
    // two pass stack: O(N)time & space, 56%, ok
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);  // initialize
        if(nums.empty()) return ret;
        stack<pair<int, int>> next;     // format: (val, index)
        int loop = 2;
        while(loop--){
            for(int i = 0; i < nums.size(); i++){
                while(next.size() && next.top().first < nums[i]){
                    int index = next.top().second;
                    if(ret[index] == -1)
                        ret[index] = nums[i];
                    next.pop();
                }
                next.push({nums[i], i});
            }
        }
        // set -1 for the largest value in vector
        int maxIdx = -1;
        while(next.size()){
            maxIdx = next.top().second;
            next.pop();
        }
        ret[maxIdx] = -1;
        return ret;
    }

    // more elegant: use stack to keep the indexes of the decreasing subsequence
    // O(N)time & space, 88.26%, ok
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);  // initialize
        if(nums.empty()) return ret;
        stack<int> next;
        for(int i = 0; i < nums.size() * 2; i++){
            int num = nums[i % nums.size()];
            while(next.size() && nums[next.top()] < num){
                ret[next.top()] = num;
                next.pop();
            }
            if(i < nums.size())   // key: key track of index
                next.push(i);
        }
        return ret;
    }
};
