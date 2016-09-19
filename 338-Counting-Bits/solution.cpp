class Solution {
public:
    // dynamic programming:
    vector<int> countBits(int num) {
        vector<int> ans(1, 0);
        for(int i = 1; i <= num; i ++)
            ans.push_back(ans[i / 2] + i % 2);
        return ans;
    }
};