class Solution {
public:
    // hashtable with the letter occurrance as key: O(N*word length), 3.2%
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.empty()) return ret;
        unordered_map<string, vector<string>> map;
        for(auto s: strs){
            vector<int> letter(26, 0);
            for(int i = 0; i < s.size(); i++)
                letter[s[i] - 'a']++;
            string key = "";
            for(int i = 0; i < 26; i++)
                key += to_string(letter[i]);
            if(map.count(key))
                map[key].push_back(s);
            else map[key] = vector<string>(1, s);
        }
        for(auto group: map)
            ret.push_back(group.second);
        return ret;
    }

    // hashtable with the sorted string root as key
    // O(N*word length*log(word length)), 47.81%, ok
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.empty()) return ret;
        unordered_map<string, vector<string>> map;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            if(map.count(key))
                map[key].push_back(s);
            else map[key] = vector<string>(1, s);
        }
        for(auto group: map)
            ret.push_back(group.second);
        return ret;
    }
};
