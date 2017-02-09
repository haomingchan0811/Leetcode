class Solution {
public:
    // O(N), 40%, ok
    int romanToInt(string s) {
        unordered_map<char, int> value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                          {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            // s[s.size()]='/x00', so value[s[s.size()]] = 0
            if(value[s[i]] < value[s[i + 1]])
                sum -= value[s[i]];
            else sum += value[s[i]];
        }
        return sum;
    }
};
