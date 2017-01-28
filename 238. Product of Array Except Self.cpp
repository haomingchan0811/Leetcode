#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // // O(N2) without division, O(N) space: TLE, didn't pass large data test case
    // // bug: element can be 0/negative!!!
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     if(!nums.size()) return nums;
    //     vector<int> ans(nums.size(), 1);
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = 0; j < nums.size(); j++){
    //             if(i != j) ans[j] *= nums[i];
    //         }
    //     }
    //     return ans;
    // }

    /* The output array(ans) does not count as extra space for the purpose of space complexity analysis.*/

    // Two way multiply: sweep forword for product(1,2,...,i-1) and backward for product(i+1,i+2,...,n)
    // O(N) without division, O(1) space: 53.83%, ok
    vector<int> productExceptSelf(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> ans(nums.size(), 1); // bug: ans[] can't be accessed when ret hasn't initialized
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            ans[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }

    // O(N) without division and without extra space: 53.83%, ok
    vector<int> productExceptSelf(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> ans(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
            ans[i] = ans[i - 1] * nums[i - 1];
        for(int i = nums.size() - 1; i > 0; i--){ // key: ans[0] = 1 serves as a extra variable to accum product
            ans[i] *= ans[0];
            ans[0] *= nums[i];
        }
        return ans;
    }
};
