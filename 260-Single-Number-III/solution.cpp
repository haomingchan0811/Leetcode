class Solution {
public:
    // linear complexity: bit manipulation
    vector<int> singleNumber(vector<int>& nums){
        int xorXY = 0;
        // exclusive or all items, result will be x xor y (numbers only showed up once)
        for(int i = 0; i < nums.size(); i ++)
            xorXY ^= nums[i];
        // finding the LSB (least significant bit): x & (-x)
        int lsb = xorXY & (-xorXY);
        int X = 0, Y = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(lsb & nums[i])
                X ^= nums[i];
            else
                Y ^= nums[i];
        }
        vector<int> ans;
        ans.push_back(X);
        ans.push_back(Y);
        return ans;
    }

    // pointer: 105ms
    /*
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int inter = nums[0];    // pointer
        int count = 1;
        int ansCount = 0;
        for(int i = 1; (i < nums.size()) && (ansCount != 2); i ++){
            count ++;
            if(!(count % 2) && (inter != nums[i])){
                ans.push_back(inter);
                ansCount += 1;
                inter = nums[i];
                count = 1;
            }
            else{
                i += 1;
                count += 1;
                inter = nums[i];
            }
        }
        if(ansCount == 1) ans.push_back(inter);
        return ans;
    }*/
};