class Solution {
public:
    // recursive: O(logN), 17.57%, ok
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        if(n == 1) return true;
        return !(n % 2) && isPowerOfTwo(n / 2);
    }

    // iterative: O(logN), 17.57%, ok
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        if(n == 1) return true;
        while(!(n % 2)) n /= 2;
        return n == 1;
    }

    // bit count: O(1), 17.57%, ok
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        bitset<32> bit(n);
        return bit.count() == 1;
    }

    // bit manipulation: O(1), 17.57%, ok
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        return !(n & (n - 1));
    }

    // kind of cheating: O(1), 17.57%, ok
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        return !((int)pow(2, 30) % n);
    }
};
