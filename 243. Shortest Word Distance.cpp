class Solution {
public:
    // Two pointers: O(N)time, O(1)space, 81.01%, ok
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()) return -1;
        int p1 = -1, p2 = -1;
        int ret = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                if(p2 != -1) ret = min(ret, abs(i - p2));
                p1 = i;
            }
            if(words[i] == word2){
                if(p1 != -1) ret = min(ret, abs(i - p1));
                p2 = i;
            }
        }
        return ret;
    }

    // more elegant, Two pointers: O(N)time, O(1)space, 81.01%, ok
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()) return -1;
        int p1 = -1, p2 = -1;
        int ret = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1) p1 = i;
            if(words[i] == word2) p2 = i;
            if(p1 != -1 && p2 != -1)
                ret = min(ret, abs(p1 - p2));
        }
        return ret;
    }
};
