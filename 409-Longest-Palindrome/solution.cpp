class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        int ans = 0;
        bool hasOddMember = false;  // whether there exists a character that shows up odd number times
        unordered_map<char, int> map;
        for(int i = 0; i < len; i ++)
            map[s[i]] += 1;
        unordered_map<char, int>::iterator it = map.begin();
        while(it != map.end()){
            if(it->second % 2 == 0)
                ans += it->second;
            else{
                hasOddMember = true;
                ans += it->second / 2 * 2;
            }
            it ++;
        }
        return hasOddMember ? ans + 1 : ans;
    }
};