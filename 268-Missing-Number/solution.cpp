class Solution {
public:
    // math solution: 29ms
    /*
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto temp: nums)
            sum += temp;
        int trueSum = nums.size() * (nums.size() + 1) / 2;
        return trueSum - sum;
    }*/

    // bit manipulation - exclusive or:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        for(auto n: nums){
            ans ^= n;
            ans ^= cur;
            cur ++;
        }
        ans ^= cur;
        return ans;
    }
};