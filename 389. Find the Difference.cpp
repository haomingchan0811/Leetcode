class Solution {
public:
    // hashtable: O(N) time, O(1) space, 44.29%, ok
    char findTheDifference(string s, string t) {
        vector<int> letter(26, 0);
        for(int i = 0; i < s.size(); i++){
            letter[s[i] - 'a']++;
            letter[t[i] - 'a']--;
        }
        letter[t[t.size() - 1] - 'a']--;
        for(int i = 0; i < 26; i++)
            if(letter[i] < 0)
                return 'a' + i;
        return 'a';
    }

    // bit manipulation: O(N) time, O(1) space, 44.29%, ok
    char findTheDifference(string s, string t) {
        char ret = 0;
        for(auto c: s) ret ^= c;
        for(auto c: t) ret ^= c;
        return ret;
    }
};
