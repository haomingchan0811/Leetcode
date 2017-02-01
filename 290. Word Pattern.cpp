class Solution {
public:
    // hash table: O(N)time & space, 38.80%
    bool wordPattern(string pattern, string str) {
        istringstream cut(str);
        vector<string> s;
        string temp;
        while(cut >> temp) s.push_back(temp);
        if(s.size() != pattern.size()) return false;
        unordered_map<char, string> ps;
        unordered_map<string, char> sp;
        for(int i = 0; i < pattern.size(); i++){
            if(!ps.count(pattern[i]) && !sp.count(s[i])){
                ps[pattern[i]] = s[i];
                sp[s[i]] = pattern[i];
            }
            else{
                if(ps[pattern[i]] != s[i] || sp[s[i]] != pattern[i])
                    return false;
            }
        }
        return true;
    }
};
