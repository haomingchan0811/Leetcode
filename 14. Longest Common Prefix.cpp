class Solution {
public:
    // O(MN), M is the length of the shortest member, 17.11%
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if(strs.empty()) return ret;
        sort(strs.begin(), strs.end()); // string sort alphabetically
        for(int i = 0; i < strs[0].size(); i++){
            // string temp = ret + strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                // no need for substr(substr() generates new string every time)
                // if(strs[j].substr(0, temp.size()) != temp)
                if(i >= strs[j].size() || strs[j][i] != strs[j - 1][i]) // wiser comparison, one char at a time(loop)
                    return ret;
            }
            // ret = temp;
            ret += strs[0][i];
        }
        return ret;
    }
};
