class Solution {
public:
    // binary search: O(logN)time, O(1)space, 11.21%, ok
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        int head = 0, tail = num;
        while(head <= tail){
            long mid = head + (tail - head) / 2; // bug: int may overflow ans leads to TLE
            long square = mid * mid;
            if(square < num) head = mid + 1;
            else if(square > num) tail = mid - 1;
            else return true;
        }
        return false;
    }

    // math, perfect square is the sum of 1+3+5+7+...
    // O(sqrt(N))time, O(1)space, 11.21%, ok
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        int i = 1;
        while(num > 0){
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
