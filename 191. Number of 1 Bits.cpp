class Solution {
public:
    // bit Manipulation: O(32), 20.3%, ok
    int hammingWeight(uint32_t n) {
      int allOne = ~0;
      n &= allOne;
      bitset<32> temp(n);
      return temp.count();
    }

    //n&(n-1) drops the lowest set bit.
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n &= n - 1;
            count++;
        }
        return count;
    }
};
