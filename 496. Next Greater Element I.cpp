class Solution {
public:
    // brute force: O(N2)time, O(N)space, 67.69%
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.empty() || nums.empty())
            return ret;
        unordered_map<int, int> greater;
        for(int i = 0; i < nums.size(); i++){
            greater[nums[i]] = -1;      // initialize
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    greater[nums[i]] = nums[j];
                    break;
                }
            }
        }
        for(int i = 0; i < findNums.size(); i++)
            ret.push_back(greater[findNums[i]]);
        return ret;
    }

    // dp(backwards scan): O(N2)time, O(N)space, 67.69%
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.empty() || nums.empty())
            return ret;
        unordered_map<int, int> greater = {{nums.back(), -1}};
        for(int i = nums.size() - 2; i >= 0; i--){
            greater[nums[i]] = -1;  // initialize
            if(nums[i] < nums[i + 1])
                greater[nums[i]] = nums[i + 1];
            else{
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] < greater[nums[j]]){
                        greater[nums[i]] = greater[nums[j]];
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < findNums.size(); i++)
            ret.push_back(greater[findNums[i]]);
        return ret;
    }

    // stack storing decreasing seq: O(N)time & space, 67.69%, ok
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret;
        if(findNums.empty() || nums.empty())
            return ret;
        stack<int> desc;  // stack to store descending sequence
        unordered_map<int, int> greater;
        for(auto n: nums){
            while(desc.size() && desc.top() < n){
                greater[desc.top()] = n;
                desc.pop();
            }
            desc.push(n);
        }
        for(int i = 0; i < findNums.size(); i++)
            ret.push_back(greater.count(findNums[i])? greater[findNums[i]]: -1);
        return ret;
    }
};s
