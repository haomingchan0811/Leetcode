class Solution {
public:
    // dp[i]: #slices ending at i;
    // O(N)time & space, 14.05%, ok
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        vector<int> slices(A.size(), 0);
        int diff = A[1] - A[0];
        for(int i = 2; i < A.size(); i++){
            int currDiff = A[i] - A[i - 1];
            if(diff == currDiff)
                slices[i] = slices[i - 1] + 1;
            else diff = currDiff;
        }
        int ret = 0;
        for(auto num: slices) ret += num;
        return ret;
    }

    // dp[i]: #slices ending at i; O(N)time, O(1)space, 14.05%, ok
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int ret = 0, prev = 0;
        for(int i = 2; i < A.size(); i++){
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
                prev++;
            else prev = 0;
            ret += prev;
        }
        return ret;
    }
};
