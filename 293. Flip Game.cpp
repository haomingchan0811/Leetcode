class Solution {
public:
    // brute force: O(N), 2.29%, ok
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ret;
        if(s.empty()) return ret;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1] && s[i] == '+'){
                string temp = s;
                temp[i] = temp[i - 1] = '-';
                ret.push_back(temp);
            }
        }
        return ret;
    }
};
