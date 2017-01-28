#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    // hashtable: O(N), 46.48%, ok
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> s1, t1;
        for(int i = 0; i < s.size(); i++){
            s1[s[i]]++;
            t1[t[i]]++;
        }
        return s1 == t1;
    }

    // further improvement: use only one hashmap, 46.48%, ok
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> s1;
        for(int i = 0; i < s.size(); i++){
            s1[s[i]]++;
            s1[t[i]]--;
        }
        for(auto it: s1)  // bug: it is a pair, not pointer
            if(it.second)
                return false;
        return true;
    }

    // another idea: use array int letter[26] to replace hashmap

    // sort and compare: O(NlogN), 28.99%
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(){
	string s = "anagram";
	string t = "nagaram";
	Solution sol;
	cout << sol.isAnagram(s, t) << endl;
}
