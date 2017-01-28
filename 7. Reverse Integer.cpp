class Solution {
public:
    // 6ms, 72.14%, ok
    int reverse(int x) {
        if(x == 0) return 0;
        long temp = 0;
        // bool isNegative = false;  // no need for "%": can handle negative case
        // if(x < 0) {x = -x; isNegative = true;}
        while(x){
            temp = temp * 10 + x % 10;
            if(temp > INT_MAX || temp < INT_MIN) // bug: deal with overflow problem
                return 0;
            x /= 10;
        }
        return int(temp);
    }
};
