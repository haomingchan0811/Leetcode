class Solution {
public:
    // reverse: O(N)time & space, 14.10%, ok
    bool isPalindrome(string s) {
        if(s.size() < 2) return true;
        string str = "";
        for(auto c: s)
            if(isalnum(c)) str += tolower(c);
        string reverseStr = str;
        reverse(str.begin(), str.end());
        return str == reverseStr;
    }

    // two pointer: O(N)time, O(1)space, 34.78%, ok
    bool isPalindrome(string s) {
        if(s.size() < 2) return true;
        int i = 0, j = s.size();
        while(i < j){
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
            i++; j--;
        }
        return true;
    }
};
