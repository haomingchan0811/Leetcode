class Solution {
public:
    // naive backtracking: O(N2), 0.37%
    bool repeatedSubstringPattern(string str) {
        if(str.size() < 2) return false;
        string pattern = string(1, str[0]), sub;
        int i = 0, j;
        for(int k = 1; k < str.size(); k++, i++){
            if(i == pattern.size()) i = 0;
            sub += str[k];
            if(str[k] != pattern[i]){
                pattern += sub[0];
                sub = "";
                i = -1;
                k = pattern.size() - 1;
            }
        }
        return !(pattern.size() == str.size()) && !(sub.size() % pattern.size());
    }

    // more elegant: for each potential repetive times, check whether the string fits the criterion
    // 49.45%, ok
    bool repeatedSubstringPattern(string str) {
        if(str.size() < 2) return false;
        int size = str.size();
        for(int l = size / 2; l > 0; l--){  // length of the repetive string can't be larger than size/2
            if(!(size % l)){
                int times = size / l;  // repetive times
                string sub = str.substr(0, l);
                string temp;
                for(int i = 0; i < times; i++) temp += sub;
                if(temp == str) return true;
            }
        }
        return false;
    }

};
