#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // brute force: O(N) time & space, 0.53%
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> number;
        for(int i = 0; i <= nums.size(); i++) number.insert(i);
        for(auto n: nums) number.erase(n);
        auto it = number.begin();
        return *it;
    }

    // sum and subtract: O(N) time, O(1)space, 54.63%, ok
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int sum = (1 + nums.size()) * nums.size() / 2;
        for(auto n: nums) sum -= n;
        return sum;
    }

    // XOR: O(N) time, O(1)space, 47.44%, ok
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 0, i = 1;
        for(auto n: nums){
            ret ^= n;
            ret ^= i++;
        }
        return ret;
    }
};

int main(){
    int test[7] = {2,1,3,5,6,0,7};
    vector<int> t(test, test + 7);
    Solution sol;
    cout << sol.missingNumber(t);
}
