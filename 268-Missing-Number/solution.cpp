class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto temp: nums)
            sum += temp;
        int trueSum = nums.size() * (nums.size() + 1) / 2;
        return trueSum - sum;
    }
};