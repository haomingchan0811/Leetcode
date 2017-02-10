class Solution {
public:
    // // brute force: match starting from head, and go on
    // // TLE for large data
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     if(wordDict.empty() || s.empty()) return false;
    //     for(int i = 0; i < wordDict.size(); i++){
    //         if(s.find(wordDict[i]) == 0){
    //             if(wordDict[i].size() == s.size())
    //                 return true;
    //             string sub = s.substr(wordDict[i].size());
    //             if(wordBreak(sub, wordDict))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    // dp: dp[i] means substring with len i starting from head is a valid one
    // O(mn)time, O(m)space, m:length of s, n:length of wordDict, 88.68%, ok
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty() || s.empty()) return false;
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= len; i++){
            for(auto w: wordDict){
                int head = i - w.size();
                if(head >= 0 && dp[head] && s.substr(head, i - head) == w){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len];
    }
};
