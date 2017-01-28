class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 1.0) return x;
        long long n1 = n;
        if(n1 < 0){     // bug: overflow (if(n < 0)), when n overflow as int
            n1 = -n1;
            x = 1 / x;
        }
        // cout << n1 << endl;
        double ans = 1;
        while(n1){
            if(n1 % 2 != 0) ans *= x;    // can also be wriiten as if(n & 1)
            x *= x;
            n1 >>= 1;
            // cout << n1 << endl;
        }
        return ans;
    }
};
