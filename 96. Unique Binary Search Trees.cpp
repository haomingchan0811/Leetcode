class Solution {
public:
    /* dp: for every i as root.
           leftChild has (i - 1) nums, thus dp[i - 1] unique ways.
           rightChild has (n - i) nums, thus dp[n - i] unique ways.
           Thus there're dp[i-1] * dp[n-i] unique ways for root i. */
    // O(N), 9.69%, ok
    int numTrees(int n) {
        vector<int> ret(2, 1);  // base case: dp[0]=dp[1]=1
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= i; j++)  // for every j as root
                sum += ret[j - 1] * ret[i - j];  // key!!!!
            ret.push_back(sum);
        }
        return ret[n];
    }
};
