#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Binary search (9ms): utilize the monotone feature
    int search(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        int mid = low + (high - low) / 2;
        while(low <= high){
           if(nums[mid] == target) return mid;
           if(nums[mid] >= nums[low]){
               if(nums[low] <= target && target < nums[mid]) high = mid;
               else low = mid + 1;
           }
           else{
               if(nums[mid] < target && target <= nums[high]) low = mid + 1;
               else high = mid;
           }
           // bug: (1)forget this line, TLE (2) redefine a local variable int mid, shoudnt include "int"
           mid = low + (high - low) / 2;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    int t[2] = {1,3};
    vector<int> test(t, t+2);
    int target = 2;
    cout << sol.search(test, target);
}
