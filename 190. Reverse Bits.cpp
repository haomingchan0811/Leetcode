class Solution {
public:
    // bitset: 6ms
    uint32_t reverseBits(uint32_t n){
        string temp = "";
        for(int i = 0; i < 32; i++){
            temp += n % 2 + '0';    // bug: n[0] % 2 invalid
            n >>= 1;                // bug: n >> 1
        }
        bitset<32> ans(temp);
        return uint32_t(ans.to_ulong());
    }

    // bitset: 6ms
    uint32_t reverseBits(uint32_t n) {
        bitset<32> original(n);
        int low = 0;
        int high = 31;
        while(high > low){
            int temp = original[high];
            original[high] = original[low];
            original[low] = temp;
            high--;
            low++;
        }
        return uint32_t(original.to_ulong());
    }
};
