class Solution {
public:
    // Greedy, initialize ascendantly, then reverse each trunk of Ds
    // O(N)time & space, 62.42%, ok
    vector<int> findPermutation(string s) {
        vector<int> ret;
        if(s.empty()) return ret;
        for(int i = 1; i <= s.size() + 1; i++)
            ret.push_back(i);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'D'){
                int head = i;
                while(i < s.size() && s[i + 1] == 'D') i++;
                int tail = i + 1;
                while(head <= tail)
                    swap(ret[head++], ret[tail--]);
            }
        }
        return ret;
    }
};
