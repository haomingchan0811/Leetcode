class Solution {
public:
    // istringstream: 3ms
    int lengthOfLastWord(string s) {
        istringstream cut(s);
        string word;
        while(cut){
            cut >> word;
        }
        if(word == "") return 0;
        return word.size();
    }

    // naive: 3ms
    int lengthOfLastWord(string s){
        int index = s.size() - 1;
        while(index >= 0 && s[index] == ' ') index--;
        int len = 0;
        while(index >= 0 && s[index] != ' ') {len++; index--;}
        return len;
    }
};
