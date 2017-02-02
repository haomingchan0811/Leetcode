class Solution {
public:
    // backtracking: for every char, either keep it or abbr it, then recursion
    // O(2^N)time & space, 92.79%, ok
    vector<string> generateAbbreviations(string word) {
        vector<string> ret;
        genAbbr(ret, 0, word, "");
        return ret;
    }

    void genAbbr(vector<string>& ret, int currIdx, string word, string abbr){
        if(currIdx == word.size()){
            ret.push_back(abbr);
            return;
        }
        genAbbr(ret, currIdx + 1, word, abbr + word[currIdx]);
        if(abbr.empty() || !isdigit(abbr[abbr.size() - 1])){
            for(int i = 1; i + currIdx <= word.size(); i++)
                genAbbr(ret, currIdx + i, word, abbr + to_string(i));
        }
    }
};  
