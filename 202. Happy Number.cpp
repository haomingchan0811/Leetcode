#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Tutorial: https://discuss.leetcode.com/topic/44468/4-c-solutions-with-explanations/2

    // hash map: 4ms brute force: 40.40%, ok
    bool isHappy_1(int n){
        unordered_map<int, int> num; // store the numbers that appeared
        while(n != 1){
            if(num.count(n)) return false;
            num[n] = 1; // flag the number
            double nextNum = 0;    // the new number of the square sum
            while(n != 0){
                int digit = n % 10;
                nextNum += pow(digit * 1.0, 2);
                n /= 10;
            }
            n = nextNum;
        }
        return true;
    }

    // Floyd's Cycle detection algorithm:
    int next(int n){
        int sum = 0;
        while(n != 0){
            sum += pow(n % 10,2);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));

        while(slow != fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1 ;
    }
};



int main(){
    int test = 19;
    Solution sol;
    cout << sol.isHappy(test) << endl;
}
