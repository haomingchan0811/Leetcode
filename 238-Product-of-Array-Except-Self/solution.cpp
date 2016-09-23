class Solution {
public:
    // Brute-force: O(n^2) - Time Limit Exceed
    /*
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
    }*/
    
    // Two way multiply : 49ms
    vector<int> productExceptSelf(vector<int>& nums){
        int len = nums.size();
        vector<int> ret(len, 1);    // bug: ret[] can't be accessed when ret hasn't initialized
        for(int i = 1; i < len; i ++)
            ret[i] = nums[i - 1] * ret[i - 1];
        int p = nums[len - 1];
        for(int i = len - 2; i >= 0; i --){
            ret[i] *= p;
            p *= nums[i];
        }
        return ret;
    }
};