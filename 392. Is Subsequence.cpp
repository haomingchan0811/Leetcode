class Solution {
public:
    // two pointers: O(M+N)time, O(1)space, 40.08%, ok
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        int i = 0, j = 0;
        while(i < s.size()){
            if(j >= t.size()) return false;
            while(j < t.size() && t[j] != s[i]) j++;
            i++; j++;
        }
        return j <= t.size(); // bug: return true
    }

    // binary search: preprocess to keep a map of index
    // O(M)time, O(1)space, 6.52%, ok
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        unordered_map<char, vector<int>> index;
        for(int i = 0; i < t.size(); i++)  // preprocess
            index[t[i]].push_back(i);

        int prevIdx = -1;
        for(auto c: s){  // binary search for every char
            vector<int> idx = index[c];
            if(idx.empty()) return false;
            int i = 0, j = idx.size() - 1;
            while(i < j){ // find smallest index that > prevIdx
                int mid = i + (j - i) / 2;
                if(idx[mid] <= prevIdx) i = mid + 1; // bug: "="
                else j = mid;
            }
            // bug: miss the "=" operator
            if(index[c][i] <= prevIdx) return false;
            else prevIdx = index[c][i];
        }
        return true;
    }
};
