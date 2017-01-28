#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // using array to represent 26 letters: traverse the array 2 times
    int firstUniqChar(string s) {
        // can be replaced by "vector<int> check(26,0)"";
        int letter[26];
        memset(letter, 0, 26 * sizeof(int)); // bug: should be 26 * sizeof(int), not 26
        int len = s.length();
        for(int i = 0; i < len; i ++)
            letter[s[i] - 'a'] ++;
        for(int i = 0; i < len; i ++)
            if(letter[s[i] - 'a'] == 1)
                return i;
        return -1;
    }

    // hash map containing pair, only traverse once
    // O(N) time, O(1) space, 23.08%, ok
    int firstUniqChar(string s){
        int len = s.length();
        unordered_map<int, pair<int, int> > letter; // (letter, (shown-up times, shown-up index))
        for(int i = 0; i < len; i ++){
            int index = s[i] - 'a';
            letter[index].first ++;
            letter[index].second = i;
        }
        int ret = len;
        for(auto it = letter.begin(); it != letter.end(); it++){
            if(it->second.first == 1)
                ret = min(it->second.second, ret);
        }
        return ret == len ? -1 : ret;
    }

    // vector: O(N) time, O(1) space, only traverse once, 86.59%, ok
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        vector<int> index(26, -1); // first index of the letter, -1 initialization, -2 means repeative appearance;
        for(int i = 0; i < s.size(); i++){
            switch(index[s[i] - 'a']){
                case -1: index[s[i] - 'a'] = i; break;
                case -2: break;
                default: index[s[i] - 'a'] = -2;
            }
        }
        int ret = s.size();
        for(int i = 0; i < 26; i++){
            if(index[i] >= 0)
                ret = min(ret, index[i]);
        }
        return ret != s.size() ? ret : -1;
    }
};

int main(){
    string test = "loveleetcode";
    Solution sol;
    cout << sol.firstUniqChar(test);
}
