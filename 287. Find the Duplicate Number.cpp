class Solution {
public:
    // // brute force: O(N2), TLE for large data case
    // int findDuplicate(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(nums[i] == nums[j])
    //                 return nums[i];
    //         }
    //     }
    //     return 0;
    // }

    // sort (modified array): O(NlogN), 16.37%
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] == nums[i - 1])
                return nums[i];
        return 0;
    }

    // binary search: O(NlogN), 30.95%, ok
    int findDuplicate(vector<int>& nums) {
        int head = 1, tail = nums.size() - 1;  // tail = n
        // vector contain n+1 integers where each integer is between 1 and n (inclusive)
        while(head < tail){
            int mid = head + (tail - head) / 2;
            int count = 0;
            for(auto num: nums)
                if(num <= mid) count++; // mid = n/2, n/4, ...
            if(count > mid) tail = mid;
            else head = mid + 1;
        }
        return head;
    }

    // two pointers, cycle detection: O(N),
    int findDuplicate(vector<int>& nums) {

    }
};
