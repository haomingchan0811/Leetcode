class Solution {
public:
    //https://leetcode.com/articles/longest-palindromic-substring/
    
    // DP: O(N2) time and space, 26.43%
    // P(i,j) = (P(i+1,j-1) && Si==Sj), filling a upper digonal matrix (base case: digonal and adjacent block)
    string longestPalindrome(string s) {
        int size = s.size();
        if(!size) return s;
        int dp[size][size];
        int longest = 1, index = 0; // maximal length and the correspoding boundary index
        for(int k = size - 1; k >= 0; k--){
            for(int i = 0; i <= k; i++){
                int j = size - 1 - k + i;
                if(i == j) dp[i][j] = 1;  // base case1
                else if(i + 1 == j) dp[i][j] = (s[i] == s[j]); // base case2
                else dp[i][j] = (dp[i + 1][j - 1]) && (s[i] == s[j]);
                if(dp[i][j] && (longest < j - i + 1)){
                    longest = j - i + 1;
                    index = i;
                }
            }
        }
        return s.substr(index, longest);
    }

    // two pointers: O(N2)time, O(1)space, 46.29%, ok
    // for every position i, try "Expand Around Center i"(odd) or "Expand Around Center between i and i + 1"(even)
    string longestPalindrome(string s) {
        int size = s.size();
        if(!size) return s;
        int longest = 0, index = 0;         // maximal length and the correspoding boundary index
        for(int i = 0; i < size; i++){
            int len1 = expand(s, i, i);     // palindrome of a single center i
            int len2 = expand(s, i, i + 1); // palindrome of a center between i and i + 1
            int len = max(len1, len2);
            if(longest < len){
                longest = len;
                index = i - (len - 1) / 2;
            }
        }
        return s.substr(index, longest);
    }

    int expand(string s, int head, int tail){
        while(head >= 0 && tail < s.size() && s[head] == s[tail]){
            head--;
            tail++;
        }
        return tail - head - 1;
    }
};
