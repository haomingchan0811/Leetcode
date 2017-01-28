class Solution {
public:
    // brute force: 80.13%, ok
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        while(n){
            if(n == 1) return true;
            if(n % 3 != 0) return false;
            n /= 3;
        }
        return true;
    }

    // recursive: 80.13%, ok
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        return (n % 3 == 0) && isPowerOfThree(n / 3);
    }

    // O(1): kind of cheating, pow(3,19) is the max int which is less than INT_MAX.
    // 3 is a prime, power of 4 would be invaild using this method
    bool isPowerOfThree(int n) {
        return (n > 0) && (int(pow(3.0, 19)) % n == 0);
    }

};
