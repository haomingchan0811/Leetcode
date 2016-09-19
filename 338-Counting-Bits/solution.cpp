class Solution {
public:
    // dynamic programming: 66ms
    // the bits of num n is the same as its floor(n/2) excpet for the last digit
    /*
    vector<int> countBits(int num) {
        vector<int> ans(1, 0);
        for(int i = 1; i <= num; i ++)
            ans.push_back(ans[i / 2] + i % 2);
        return ans;
    }*/

    // dynamic programming, a more easy-understanding way: 63ms
    vector<int> countBits(int num) {
        // initialize num = 0,1,2
        vector<int> ans(1, 0);
        int nearestPow = 1;     // current nearest power of 2
        for(int i = 1; i <= num; i ++){
            // check whether i is a power of 2, ans[n] = ans[its nearestPow] + ans[n-nearestPow]
            if(i & (i - 1)){
                ans.push_back(ans[nearestPow] + ans[i - nearestPow]);
            }
            else{
                ans.push_back(1);
                nearestPow = i;
            }
        }
        return ans;
    }
};