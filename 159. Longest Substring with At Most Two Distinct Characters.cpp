class Solution {
public:
    // // brute force with hash table: O(N3)time, O(N)space, TLE for large data
    // int lengthOfLongestSubstringTwoDistinct(string s) {
    //     if(s.empty()) return 0;
    //     int ret = 1;
    //     for(int i = 0; i < s.size(); i++){
    //         for(int j = 2; i + j - 1 < s.size(); j++){
    //             string sub = s.substr(i, j);
    //             unordered_map<char, int> cnt;
    //             for(int k = 0; k < sub.size(); k++)
    //                 cnt[sub[k]]++;
    //             if(cnt.size() <= 2)
    //                 ret = max(ret, int(sub.size()));
    //         }
    //     }
    //     return ret;
    // }

    // record latest index for each distinct char, remove the one that has the smallest rightmost index and update length
    // O(N)time & space, 41.81%, ok
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty()) return 0;
        int ret = 0, head = -1;
        unordered_map<char, int> index;
        for(int i = 0; i < s.size(); i++){
            index[s[i]] = i;
            if(index.size() > 2){
                pair<char, int> temp = {' ', INT_MAX};
                for(auto p: index)  // find the char that has the smallest rightmosr index
                    if(temp.second > p.second)
                        temp = p;
                head = temp.second;
                index.erase(temp.first);
            }
            ret = max(ret, i - head);

        }
        return ret;
    }

    // O(N)time, O(1)space
};
