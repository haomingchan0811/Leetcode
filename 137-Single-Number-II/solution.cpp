class Solution {
public:
    // bit manipulation, a more delicate way
    int singleNumber(vector<int> nums){
        int bit[32];
        for(int i = 0; i < 32; i ++)    // initialize to record each bit's status
            bit[i] = 0;

        for(int i = 0; i < 32; i ++){
            int temp = 1 << i;      // each bit count
            for(int j = 0; j < nums.size(); j ++){
                if(nums[j] & temp)
                    bit[i] += 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i ++){
            int temp = 1 << i;
            ans += (bit[i] % 3) * temp;
        }
        return ans;
    }

    // bit-manipulation: 23ms
    /*
    int singleNumber(vector<int>& nums) {
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
    }*/
};