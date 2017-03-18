class Solution {
public:
    // math, Newton's iterative method: O(logN)time, O(1)space, 8.32%
    // https://discuss.leetcode.com/topic/8689/newton-s-iterative-method-in-c
    int mySqrt(int x) {
        long long r = x;  // bug: int will overflow
        while(r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
    
    // binary search: O(logN)time, O(1)space, 24.08%, ok
    int mySqrt(int x) {
       int head = 0, tail = x;
       while(head < tail){
           long mid = head + (tail - head) / 2;   // bug: int overflow
           if(mid * mid > x) tail = mid - 1;
           else{                // bug: not traditional binary search
               if((mid + 1) * (mid + 1) > x)
                    return mid;
                else head = mid + 1;
           }
       }
       return head;
    }
};