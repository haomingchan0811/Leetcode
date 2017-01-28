#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // hashtable: O(N) time and space, 28.19%
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> flag;
        for(int i = 0; i < nums.size(); i++)
            flag[nums[i]]++;
        for(auto it = flag.begin(); it !=flag.end(); it++)
            if(it->second < 3)
                return it->first;
        return 0;
    }

    // bit manipulation, without extra memory: 19ms
    // O(N) time, O(1) space, 28.19%, ok
    int singleNumber(vector<int> nums){
        int ans = 0;
        for(int i = 0; i < 32; i ++){
            int bit = 1 << i;           // location of specific bit
            int count = 0;              // bit count
            for(int j = 0; j < nums.size(); j ++)
                if(bit & nums[j]) count ++;
            if(count % 3) ans += bit;
        }
        return ans;
    }

    // bit manipulation: record each bit's appearance mod 3
    // O(N) time and O(32) space, 3.19%
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int bit[32] = {0};
        for(int i = 0; i < nums.size(); i++){
            bitset<32> temp(nums[i]);
            for(int j = 0; j < 32; j++)
                if(temp[j]) bit[j]++;
        }
        int ret = 0;
        for(int i = 0; i < 32; i++)
            if(bit[i] % 3)
                // bug: pow(2.0, i) will overflow, should convert to int
                // in two's complement: bit 32 is a sign bit, 1 represents -2^31
                ret += int(pow(2.0, i));
        return ret;
    }

    // 分类讨论 naive
    int singleNumber_1(vector<int>& nums) {
        unordered_map<int, int> flag; // whether an integer showed up before
        int ans = 0;
        if(nums.size() % 3 == 1){
            for(auto num: nums){
                if(!flag.count(num)){
                    ans ^= num;
                    flag[num] = 1;
                }
                else if(flag[num] == 1){
                    ans ^= num;
                    flag[num] += 1;
                }
            }
            return ans;
        }
        else{
            for(auto num: nums){
                ans ^= num;
                if(!flag.count(num)){
                    flag[num] = true;
                    ans ^= num;
                }
            }
        }
        return ans;
    }
};

int main(){
    int test[12] = {-3,-3,-3,2,2,2,4,4,4,-10,-10};
    vector<int> t(test, test + 10);
    Solution sol;
    cout << sol.singleNumber(t) << endl;
}
