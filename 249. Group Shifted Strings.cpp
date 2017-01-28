class Solution {
public:
    // // brute force: O(N2), 21.10%
    // vector<vector<string>> groupStrings(vector<string>& strings) {
    //     vector<vector<string>> ret;
    //     if(strings.empty()) return ret;
    //     unordered_map<string, vector<string>> group;
    //     set<int> length;
    //     for(auto s: strings){
    //         if(!length.count(s.size())) {
    //             group[s] = vector<string>(1, s);
    //             length.insert(s.size());
    //         }
    //         else{
    //             bool found = false;
    //             for(auto it = group.begin(); it != group.end(); it++){
    //                 if(it->first.size() == s.size()){
    //                     int len = s[0] - it->first[0];
    //                     bool match = true;
    //                     for(int i = 1; i < s.size(); i++){
    //                         int len1 = s[i] - it->first[i];
    //                         // bug: when len == len1 == 0
    //                         if(((len * len1 >= 0) && (len != len1)) || ((len * len1 < 0) && ((abs(len) + abs(len1) != 26)))){
    //                             match = false;
    //                             break;
    //                         }
    //                     }
    //                     if(match) {
    //                         found = true;
    //                         group[it->first].push_back(s);
    //                         break;
    //                     }
    //                 }
    //             }
    //             if(!found) group[s] = vector<string>(1, s);
    //         }
    //     }
    //     for(auto it = group.begin(); it != group.end(); it++)
    //         ret.push_back(it->second);
    //     return ret;
    // }

    // more elegant: find the shifted root starting with an 'a', O(N), 60.88%, ok
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        if(strings.empty()) return ret;
        unordered_map<string, vector<string>> group;
        for(auto s: strings){
            string key = findKey(s);
            group[key].push_back(s);
        }
        for(auto g: group)
            ret.push_back(g.second);
        return ret;
    }

    string findKey(string s){
        string ret = "a";
        int diff = s[0] - 'a';
        for(int i = 1; i < s.size(); i++){
            char temp = s[i] - diff >= 'a' ? s[i] - diff : 26 + s[i] - diff;
            ret += string(1, temp);
        }
        return ret;
    }
};
