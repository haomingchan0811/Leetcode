class Solution {
public:
    // Brute-force: O(n^2)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int len = nums.size();
        int *pro = new int[len];
        for(int i = 0; i < len; i ++)
            pro[i] = 1;
        for(int i = 0; i < len; i ++){
            for(int j = 0; j < len; j ++){
                if(j != i) 
                    pro[j] *= nums[i];
            }
        }
        for(int i = 0; i < len; i ++)
            ret.push_back(pro[i]);
        delete [] pro;
        return ret;
    }
};