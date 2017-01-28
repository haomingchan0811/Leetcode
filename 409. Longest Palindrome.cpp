class Solution {
public:
    // hashtable: O(N)time, O(1)space, 32.77%
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        int ret = 0;
        bool odd = false;
        unordered_map<char, int> letter;
        for(auto c: s) letter[c]++;
        for(auto it = letter.begin(); it != letter.end(); it++){
            if(it->second % 2){
                odd = true;
                ret += it->second - 1;  // bug: miss this line
            }
            else ret += it->second;
        }
        return odd? ret + 1 : ret;
    }
};
