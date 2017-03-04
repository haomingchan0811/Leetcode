class Solution {
public:
    // hashmap & two pointers & queue: O(N)time & space, 25.91%, ok
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ret = 0, start = 0;
        unordered_map<int, int> map;
        queue<char> record;
        for(int i = 0; i < s.size(); i++){
            record.push(s[i]);
            if(map.count(s[i])){
                ret = max(ret, i - start);
                start = map[s[i]] + 1;
                while(record.front() != s[start]){
                    map.erase(record.front());
                    record.pop();
                }
            }
            map[s[i]] = i;
        }
        ret = max(ret, int(s.size()) - start);
        return ret;
    }

    // hashmap & two pointers: O(N)time & space, 51.17%, ok
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int ret = 0, start = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) && map[s[i]] >= start){  // replace queue
                ret = max(ret, i - start);
                start = map[s[i]] + 1;
            }
            map[s[i]] = i;
        }
        ret = max(ret, int(s.size()) - start);
        return ret;
    }
};
