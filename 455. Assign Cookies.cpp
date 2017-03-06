class Solution {
public:
    // Greedy and sort: O(min(mlogM, nlogN))time, O(1)space, 63.37%, ok
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ret = 0, i = 0, j = 0;
        while(i < s.size() && j < g.size()){
            if(s[i] >= g[j]) {ret++; i++; j++;}
            else i++;
        }
        return ret;
    }
};
