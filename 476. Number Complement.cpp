class Solution {
public:
    // tradition way: O(logN)time, O(1)space, 5.98%, ok
    int findComplement(int num) {
        int i = 1, ret = 0;
        if(num == 1) return 0;
        while(num != 1){
            if(num % 2 == 0)
                ret += i;
            i *= 2;
            num /= 2;
        }
        return ret;
    }

    // bitset: O(1)time & space, 69.25%, ok
    int findComplement(int num) {
        bitset<32> ret = num;
        for(int i = 31; i >= 0; i--){
            if(ret[i] == 1){
                for(int j = 0; j <= i; j++)
                    ret.flip(j);
                break;
            }
        }
        return ret.to_ulong();
    }

    // bit mask: O(1)time & space, 5.98%, ok
    int findComplement(int num) {
        int mask = ~0;
        // key: find the mask that shield all leading 0s of num
        while(num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
