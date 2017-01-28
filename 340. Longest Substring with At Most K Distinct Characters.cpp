struct cmp{
  bool operator() (pair<char, int> a, pair<char, int> b){
      return a.second > b.second;
  }
};

class Solution {
public:
    // // brute force & hash table: O(n3)time, O(n)space, TLE for 2 large data case
    // int lengthOfLongestSubstringKDistinct(string s, int k) {
    //     if(!s.size()) return 0;
    //     int ret = 0;
    //     for(int i = 0; i < s.size(); i++){
    //         for(int j = 1; i + j - 1 < s.size(); j++){
    //             string sub = s.substr(i, j);
    //             unordered_map<char, int> cnt;
    //             bool match = true;
    //             for(int p = i; p < i + j; p++){
    //                 cnt[s[p]]++;
    //                 if(cnt.size() > k) {
    //                     match = false;
    //                     break;
    //                 }
    //             }
    //             if(match) ret = max(ret, (int)sub.size());
    //         }
    //     }
    //     return ret;
    // }

    // record the rightmost index for each distinct char, new substring start from the smallest index
    // O(n)time & space, 56.31%, ok
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(!s.size() || k <= 0) return 0;
        int ret = 0, head = -1;
        // keep track of the rightmost index of each character
        unordered_map<char, int> loc;
        for(int i = 0; i < s.size(); i++){
            loc[s[i]] = i;
            if(loc.size() > k) {
                head = INT_MAX;
                char deleteChar;
                for(auto pair: loc){
                    if(head > pair.second){
                        head = pair.second;
                        deleteChar = pair.first;
                    }
                }
                loc.erase(deleteChar);
            }
            ret = max(ret, i - head);
        }
        return ret;
    }
};
