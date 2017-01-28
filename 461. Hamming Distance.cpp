class Solution {
public:
    // bitset: O(1)time & space, 1.95%, ok
    int hammingDistance(int x, int y) {
        bitset<32> x1(x);
        bitset<32> y1(y);
        int ret = 0;
        for(int i = 0; i < 32; i++)
            ret += x1[i] != y1[i];
        return ret;
    }

    // bit: O(1)time & space, 1.95%, ok
    int hammingDistance(int x, int y) {
        int ret = 0;
        for(int i = 0; i < 32; i++){
            ret += (x & 1) != (y & 1);
            x = x >> 1;
            y = y >> 1;
        }
        return ret;
    }

    // exclusive or: O(1)time & space, 1.95%, ok
    int hammingDistance(int x, int y) {
        bitset<32> ret(x ^ y);
        return ret.count();
    }

    // erase rightmost 1 bit: O(1)time & space, 1.95%, ok
    int hammingDistance(int x, int y) {
        int ret = 0, n = x ^ y;
        while(n){
            ret++;
            n &= n - 1;
        }
        return ret;
    }
};
