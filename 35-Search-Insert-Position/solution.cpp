class Solution {
public:
    // optimized & concise edition: 6ms
    /*
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){     // opt: don't need to check empty vector cause high = -1 < low
            int mid = low + (high - low)/2; // better than (low+high)/2 cause low+high may overflow
            if(nums[mid] < target)
                low = mid + 1;
            // else if(nums[mid] == target) return mid; // no need, trick
            else high = mid - 1;
        }  
        return low;
    }*/
    
    // brute-force:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i ++)
            if(target <= nums[i])
                return i;
    }


    
    // original thought: 6ms
    /*
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len) return 0;
        if(target < nums[0]) return 0;
        if(target > nums[len - 1]) return len;
        int low = 0, high = len - 1;
        int record;
        while(low <= high){
            int mid = (low + high) / 2;
            printf("%d-%d-%d\n", low, mid, high);
            if(low == high){ 
                if(target > nums[mid]) return mid + 1;
                else return mid; // bug: if target<nums[mid], also shuould return mid (insertion)
            }
            if(target > nums[mid]) low = mid + 1; 
            else if(target == nums[mid]) return mid;
            else {high = mid - 1; record = mid;} // bug: missing "record = mid" and return record when loops end
        }
        return record;  // if low > high, the last iteration must be high=mid-1, cause mid>=low
    }*/
};