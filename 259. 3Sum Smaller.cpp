class Solution {
public:
    // two pointers: O(N2), 40.19%, ok
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int head = i + 1, tail = nums.size() - 1;
            while(head < tail){
                while(head < tail && nums[i] + nums[head] + nums[tail] >= target) tail--;
                count += tail - head;
                head++;  // duplicates allowed for this problem
            }
        }
        return count;
    }
};
