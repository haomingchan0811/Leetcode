class Solution {
public:
    // hashtable: O(N) time & space, 22.31%, ok
    bool canPermutePalindrome(string s) {
        if(s.empty()) return true;
        unordered_map<char, int> letter;
        for(auto c: s) letter[c]++;
        int odd = 0;
        for(auto l: letter){
            if(l.second % 2) odd++;
            if(odd > 1) return false;
        }
        return true;
    }

    // hashset: O(NlogN)time O(N)space, 0.63%, ok
    bool canPermutePalindrome(string s) {
        if(s.empty()) return true;
        set<char> letter;
        for(auto c: s)
            if(letter.count(c)) letter.erase(c);
            else letter.insert(c);
        return !letter.size() || letter.size() == 1;
    }

    // bitset: brilliant O(N)time, O(1)space, 22.31%, ok
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (char c : s) b.flip(c);
        return b.count() < 2;
    }
};
