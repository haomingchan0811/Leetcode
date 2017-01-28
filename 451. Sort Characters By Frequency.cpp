class Solution {
private:
    unordered_map<char, int> cnt;
public:
    // hashtable and sort: O(NlogN)time, O(1)space, 78.28%, ok
    string frequencySort(string s) {
        if(s.empty()) return s;
        for(auto c: s) cnt[c]++;
        vector<pair<char, int>> v;
        for(auto p: cnt) v.push_back(p);
        sort(v.begin(), v.end(), mySort);
        string ret;
        for(auto p: v)
            ret.append(p.second, p.first);
        return ret;
    }

    static bool mySort(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    }

    // sort with STL: (NlogN) time, O(1)space, 78.28%, ok
    string frequencySort(string s) {
        if(s.empty()) return s;
        for(auto c: s) cnt[c]++;
        sort(s.begin(), s.end(), mySort2);
        return s;
    }

    static bool mySort2(char a, char b){
        return cnt[a] > cnt[b];
    }

    // bucket without sort: O(N)time & space, 26.76%, ok
    string frequencySort(string s) {
        if(s.empty()) return s;
        int maxCnt = 0;
        for(auto c: s) {
            cnt[c]++;
            maxCnt = max(maxCnt, cnt[c]);
        }
        vector<string> substr(maxCnt + 1, "");
        for(auto p: cnt)
            substr[p.second].append(p.second, p.first);
        string ret;
        for(int i = maxCnt; i > 0; i--)
            ret += substr[i];
        return ret;
    }
};
