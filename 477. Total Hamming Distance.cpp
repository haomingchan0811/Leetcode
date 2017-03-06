class Solution {
public:
    // // brute force + hashmap: O(N2)time, O(1)space, TLE for large data
    // int totalHammingDistance(vector<int>& nums) {
    //     if(nums.empty()) return 0;
    //     int ret = 0;
    //     unordered_map<int, bitset<32>> map;
    //     for(int i = 0; i < nums.size(); i++)
    //         map[nums[i]] = bitset<32>(nums[i]);
    //     for(int i = 0; i < nums.size(); i++){
    //         bitset<32> a = map[nums[i]];
    //         for(int j = i + 1; j < nums.size(); j++){
    //             bitset<32> b = map[nums[j]];
    //             b ^= a;
    //             ret += b.count();
    //         }
    //     }
    //     return ret;
    // }

    // operate on 1 bit (rightmost) each time: M nums who have 1 as last bit and (n-M) who have 0 as
    // last bit will contribute M * (n-M) hamming distance. Iterate over 32 bits.
    // O(32N)time, O(1)space, 95.52%, ok
    int totalHammingDistance(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret = 0;
        for(int i = 0; i < 32; i++){
            int countBit = 0;
            for(int j = 0; j < nums.size(); j++)
                // check whether last bit is 1
                countBit += (nums[j] >> i) & 1;
            ret += countBit * (nums.size() - countBit);
        }
        return ret;
    }
};
