class Solution {
public:
    // brute force: O(N)time & space, 49.8%, ok
    string licenseKeyFormatting(string S, int K) {
        string s, ret;
        for(auto c: S)
            if(c != '-') s += toupper(c);
        if(s.size() <= K) return s;
        int head = s.size() % K;
        int i = 0;
        int cnt = head? K : 0;  // bug: when head == 0 in the first place, should set cnt to 0
        while(head--) ret += s[i++];
        while(i < s.size()){
            if(cnt == K){
                ret += "-";
                cnt = 0;  // bug: forget to reset
            }
            ret += s[i++];
            cnt++;
        }
        return ret;
    }

    // reverse and brute force: O(N)time & space, 49.8%, ok
    string licenseKeyFormatting(string S, int K) {
        if(S.empty()) return S;
        string ret;
        reverse(S.begin(), S.end());
        int cnt = 0;
        for(auto c: S){
            if(c != '-') {
                if(cnt == K) {  // bug: put this loop outside the '-' check, may cause extra '-' at tail
                    ret += "-";
                    cnt = 0;
                }
                ret += toupper(c);
                cnt++;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
