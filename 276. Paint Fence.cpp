class Solution {
public:
    // DP with two situation: O(N) time & space; 14.8%, ok
    int numWays(int n, int k) {
        if(!k || !n) return 0;
        if(n == 1) return k;  // bug: corner case
        vector<int> same(n, k);
        vector<int> diff(n, k);
        same[1] = k;
        diff[1] = k * (k - 1);    // base case
        for(int i = 2; i < n; i++){
            same[i] = diff[i - 1];
            diff[i] = (diff[i - 1] + same[i - 1]) * (k - 1);
        }
        return same[n - 1] + diff[n - 1];
    }

    // DP: O(N) time, O(1) space; 14.8%, ok
    int numWays(int n, int k) {
        if(!k || !n) return 0;
        if(n == 1) return k;  // bug: corner case
        int same = k;
        int diff = k * (k - 1);    // base case
        for(int i = 2; i < n; i++){
            int temp = same;
            same = diff;
            diff = (diff + temp) * (k - 1);
        }
        return same + diff;
    }
};
