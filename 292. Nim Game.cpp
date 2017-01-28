class Solution {
public:
    // ok, O(1)
    bool canWinNim(int n) {
        if(n % 4 == 0) return false;
        return true;
    }
};
