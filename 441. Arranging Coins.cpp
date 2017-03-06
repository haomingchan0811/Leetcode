class Solution {
public:
    // math & binary search; O(logN)time, 58.75%, ok
    int arrangeCoins(int n) {
        if(n < 1) return 0;
        int head = 1, tail = n, ret = -1;
        while(head <= tail){
            int mid = head + (tail - head) / 2;
            double sum = (1.0 + mid) * mid / 2; // bug: 1 -> 1.0
            if(sum == n) return mid;
            if(sum < n) { ret = mid; head = mid + 1;}
            else tail = mid - 1;
        }
        return ret;
    }

    // math: 韦达定理 O(1)time
};
