class Solution {
public:
    // dp: O(Nk)time (k is the size of primes), O(N)space, 83.92%, ok
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(primes.empty() || n <= 0) return 0;
        vector<int> ret(n + 1, INT_MAX);
        ret[1] = 1;
        vector<int> idx(primes.size(), 1);  // store the index of the un-cooperate ugly number of each prime
        for(int j = 2; j <= n; j++){
            for(int i = 0; i < primes.size(); i++)
                ret[j] = min(ret[j], primes[i] * ret[idx[i]]);
            for(int i = 0; i < primes.size(); i++){
                if(primes[i] * ret[idx[i]] == ret[j]){
                    idx[i]++;
                }
            }
        }
        return ret[n];
    }
};
