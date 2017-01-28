#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // two pointers, O(N) without extra space: 90.79%, ok
    void moveZeroes(vector<int>& nums) {
        int cur = 0, lastNonZero = 0;   // trick here
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] != 0){
                swap(nums[lastNonZero], nums[i]); // swap 0 with non-zero number
                lastNonZero ++;
            }
        }
    }
    // Tutorial: https://leetcode.com/articles/move-zeroes/
};

int main(){
    int test[] = {0, 1, 0, 3, 12};
    int len = sizeof(test) / sizeof(int);
    Solution sol;
    vector<int> nums(test, test + len);
    sol.moveZeroes(nums);
    for(int i = 0; i < nums.size(); i ++){
        cout << nums[i] << endl;
    }
}
