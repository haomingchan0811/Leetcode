class WordDistance {
private:
    unordered_map<string, vector<int>> index;
public:
    // int shortest(string word1, string word2) {
    //     vector<int> w1 = index[word1], w2 = index[word2];
    //     int i = 0, j = 0, p1 = -1, p2 = -1;
    //     int ret = INT_MAX;
    //     while(i < w1.size() && j < w2.size()){
    //         if(w1[i] < w2[j]){
    //             if(p2 != -1)
    //                 ret = min(ret, abs(w1[i] - p2));
    //             p1 = w1[i++];
    //         }
    //         else{
    //             if(p1 != -1)
    //                 ret = min(ret, abs(w2[j] - p1));
    //             p2 = w2[j++];
    //         }
    //     }
    //     while(i < w1.size()){
    //         if(p2 != -1)
    //             ret = min(ret, abs(w1[i] - p2));
    //         p1 = w1[i++];
    //     }
    //     while(j < w2.size()){
    //         if(p1 != -1)
    //             ret = min(ret, abs(w2[j] - p1));
    //         p2 = w2[j++];
    //     }
    //     return ret;
    // }

    // pre-record location, then the same as problem I
    // O(N)time & space, 87%, ok
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++)
            index[words[i]].push_back(i);
    }

    // more elegant
    int shortest(string word1, string word2) {
        vector<int> w1 = index[word1], w2 = index[word2];
        int i = 0, j = 0;
        int ret = INT_MAX;
        while(i < w1.size() && j < w2.size()){
            ret = min(ret, abs(w1[i] - w2[j]));
            w1[i] < w2[j]? i++ : j++;
        }
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
