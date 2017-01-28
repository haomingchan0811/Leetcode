#include <iostream>
#include <vector>
using namespace std;

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
        vector<int> ans(1, 0);  // bug: initialize more than 1 number, the WA for num = 0
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

    // O(n*sizeof(integer)) with bitset, O(N) space, 64.65%, ok
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; i++){
            bitset<32> temp(i);
            ret.push_back(temp.count());
        }
        return ret;
    }

    // O(N) time and space: 85.79%, ok
    vector<int> countBits(int num){
        vector<int> ret(num + 1, 0);
        for(int i = 1; i <= num; i++)
            ret[i] = ret[i & (i - 1)] + 1;
        return ret;
    }
};

int main(){
	// default test case
    Solution sol;
	vector<int> ans;
    int num = 5;
    ans = sol.countBits(num);
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i] << endl;
}
