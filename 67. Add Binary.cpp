class Solution {
public:
    // brute force: O(max(m, n)), 24.72%, ok
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string ret;
        for(i, j; i >=0 || j >= 0 || carry; i--, j--){
            int cnt = carry;  // count how much 1s
            if(i >= 0) cnt += a[i] - '0';
            if(j >= 0) cnt += b[j] - '0';
            carry = cnt > 1? 1 : 0;
            ret += to_string(cnt % 2? 1: 0);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
