class Solution {
public:
    // brute force: O(N)time & space, 52.28%, ok 
    void rotate(vector<int>& nums, int k) {
        vector<int> ret;
        // great thought! If k > nums.size()
        int start = nums.size() - (k % nums.size());  
        for(int i = start; i < nums.size(); i++)
            ret.push_back(nums[i]);
        for(int i = 0; i < start; i++)
            ret.push_back(nums[i]);
        nums = ret;
    }
    
    // in place: O(kN)time, O(1)space, 0.48% 
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), it = 0;
        int iteration = k % size;
        while(it++ < iteration){
            int prev = nums[size - 1];
            for(int i = 0; i < size; i++){
                int temp = nums[i];
                nums[i] = prev;
                prev = temp;
            }
        }
    }
    
    // in place: O(N)time, O(1)space, 37.98%, ok
    void rotate(vector<int>& nums, int k) {
        int offset = k % nums.size();
        int count = 0, i = 0, prev = nums[0], start = 0;
        while(count < nums.size()){
            i = (i + offset) % nums.size();
            int temp = nums[i];
            nums[i] = prev;
            prev = temp;
            count++;
            // bug: when k = 2, it has a circle, should break it into two chains
            if(i == start) {
                i++;
                prev = nums[i];
                start = i;   // crucial!!!
            }
        }
    }
    
    // reverse three times: O(N)time, O(1)space, 52.28%, ok 
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % nums.size());
        reverse(nums.begin() + k % nums.size(), nums.end());
    }
    
};