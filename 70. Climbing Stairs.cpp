#include <iostream>
using namespace std;

class Solution {
public:
    // dp, O(N) time and space, 8.98%, ok
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n == 1 || n == 2) return n;
        int* step = new int[n + 1];
        step[1] = 1, step[2] = 2;
        for(int i = 3; i <=n; i++){
            step[i] = step[i - 1] + step[i - 2];
        }
        return step[n];
    }

    // dp, O(N) time O(1) space, 8.98%, ok
    int climbStairs(int n) {
        if(n <= 0)  return 0;
        if(n == 1)  return 1;
        if(n == 2)  return 2;

        // recursion: TLE
        // else return climbStairs(n - 1) + climbStairs(n - 2);

        // dynamic programming without recursion
        int ans = 0;   // ans[n]
        int one_step_before = 2;    // ans[n - 1], initialize to ans[2] = 2
        int two_step_before = 1;    // ans[n - 2], initialize to ans[1] = 1
        for(int i = 3; i <= n; i ++){
            ans = one_step_before + two_step_before;
            two_step_before = one_step_before;
            one_step_before = ans;  // bug: mistaken the order of the assignment
        }
        return ans;
    }


};

int main(){
    int test = 2;
    Solution sol;
    cout << sol.climbStairs(test) << endl;
}
