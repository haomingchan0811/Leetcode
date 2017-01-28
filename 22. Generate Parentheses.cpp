class Solution {
public:
    // backtracking : 83.75%, ok
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(!n) return vector<string>(1, "");
        helper("", n, n, ret);
        return ret;
    }

    void helper(string curr, int left, int right, vector<string>& ret){
        if(!left && !right){
            ret.push_back(curr);
            return;
        }
        if(left) helper(curr + "(", left - 1, right, ret);
        if(right > left)
            helper(curr + ")", left, right - 1, ret);
    }
};
