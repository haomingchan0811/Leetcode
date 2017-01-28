class Solution {
public:
    // 0ms: with constant mem (k)
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){
            ans.push_back(1);
            int snapshot = ans[0];
            for(int j = 1; j < i; j++){
                int prev = ans[j];      // tricky part
                ans[j] += snapshot;
                snapshot = prev;
            }
        }
        return ans;
    }
};
