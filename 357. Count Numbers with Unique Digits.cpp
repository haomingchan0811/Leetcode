class Solution {
public:
    // math & dp: O(1)time & space, 13.25%, ok
    int countNumbersWithUniqueDigits(int n) {
        if(!n) return 1;  // corner case
        int ret = 10;     // when length = 1
        int multi = 9;
        int product = 9;
        while(n > 1 && multi > 0){  // when length > 10, no longer changes
            product *= multi--;
            ret += product;
            n--;
        }
        return ret;
    }

};
