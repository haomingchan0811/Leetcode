class Solution {
public:
    // backtracking: 51.29%, ok
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        dfs(ret, vector<int>(), n);
        return ret;
    }

    void dfs(vector<vector<int>>& ret, vector<int> temp, int n){
        // the smallest factor so far
        int i = temp.empty()? 2: temp.back();
        for(; i * i <= n; i++){
            if(n % i == 0){
                temp.push_back(i);
                dfs(ret, temp, n / i);
                temp.pop_back();
            }
        }
        temp.push_back(n);
        if(temp.size() > 1)
            ret.push_back(temp);
    }
};
