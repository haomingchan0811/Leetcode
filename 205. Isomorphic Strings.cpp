class Solution {
public:
    // hashtables: O(N)time & space, 50.93%, ok
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, char> s2t, t2s;
        for(int i = 0; i < s.size(); i++){
            if(!s2t.count(s[i]) && !t2s.count(t[i])){
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else if(s2t[s[i]] == t[i] && t2s[t[i]] == s[i])
                continue;
            else
                return false;
        }
        return true;
    }

    // without hashtables: assign corresponding char pair with same index
    // O(N)time, O(1)space, 69.15%, ok
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> sDict(256, -1);
        vector<int> tDict(256, -1); // bug: 未定义的数组全部初始化为0，所以小心 i = 0
        for(int i = 0; i < s.size(); i++){
            if(sDict[(int)s[i]] != tDict[(int)t[i]])
                return false;
            sDict[(int)s[i]] = tDict[(int)t[i]] = i;  // brilliant: sign the pair to the same index
        }
        return true;
    }
};
