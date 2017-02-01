class Solution {
private:
    vector<string> p = {"11", "69", "88", "96"};
public:
    // Recursion: O(?)time space, 96.49%, ok
    vector<string> findStrobogrammatic(int n) {
       return helper(n, n);
    }

    vector<string> helper(int n, int m){
        vector<string> ret;
        if(n < 0) return ret;
        if(n == 0) {ret = {""}; return ret;}
        if(n == 1) {ret = {"0", "1", "8"}; return ret;}
        vector<string> prev = helper(n - 2, m);
        for(int i = 0; i < prev.size(); i++){
            for(int j = 0; j < 4; j++)
                ret.push_back(p[j][0] + prev[i] + p[j][1]);
            if(n != m) ret.push_back("0" + prev[i] + "0");  // bug: miss the check "if(n != m)"
        }
        // sort(ret.begin(), ret.end());
        return ret;
    }
};
