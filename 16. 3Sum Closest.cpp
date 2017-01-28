class Solution {
public:
    // Two pointers: O(N2), 58.56%, ok
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++){
            int head = i + 1, tail = nums.size() - 1;
            while(head < tail){
                int sum = nums[i] + nums[head] + nums[tail];
                if(abs(sum - target) < abs(ret - target))
                    ret = sum;
                if(sum - target == 0) return sum;
                else if(sum < target) head++;
                else tail--;
            }
        }
        return ret;
    }
};
