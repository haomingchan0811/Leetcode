class Solution {
public:
    // Two pointers: O(N)time, O(1)space, 39.35%
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()) return 0;
        int ret = INT_MAX;
        if(word1 == word2){
            int index = -1;
            for(int i = 0; i < words.size(); i++)
                if(words[i] == word1){
                    if(index != -1)
                        ret = min(ret, i - index);
                    index = i;
                }
        }
        else{
            vector<int> ptr(3, -1);  // two pointers to words
            for(int i = 0; i < words.size(); i++){
                if(words[i] == word1) ptr[1] = i;
                if(words[i] == word2) ptr[2] = i;
                if(ptr[2] != -1 && ptr[1] != -1)
                    ret = min(ret, abs(ptr[1] - ptr[2]));
            }
        }
        return ret;
    }

    // combine if loop: Two pointers, O(N)time, O(1)space, 81.13%, ok
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()) return 0;
        int ret = INT_MAX;
        vector<int> ptr(3, -1);  // two pointers to words
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1) ptr[1] = i;
            if(words[i] == word2){
                if(word1 == word2)
                    swap(ptr[1], ptr[2]); // brilliant idea
                ptr[2] = i;
            }
            if(ptr[2] != -1 && ptr[1] != -1)
                ret = min(ret, abs(ptr[1] - ptr[2]));
        }
        return ret;
    }
};
