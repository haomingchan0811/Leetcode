class Solution {
public:
    // // brute force: O(logN), a number n will have at most O(logN), 20.36%, ok
    // int findNthDigit(int n) {
    //     if(n < 10) return n;
    //     // bug: "int" -> overflow while testing (sum < n)
    //     long sum = 0;  // number of accumulated digits
    //     int m = 0;    // m-digit number
    //     while(sum < n)
    //         sum += 9 * pow(10, m++) * m; // number of digits in all m-digit numbers
    //     if(sum == n) return 9;
    //     long residual = n - sum + 9 * pow(10, m - 1) * m;
    //     long num = pow(10, m - 1) + residual / m - 1;
    //     if(residual % m == 0) return num % 10;
    //     else return ((num + 1) / int(pow(10, m - residual % m))) % 10;
    // }

    // more elegant: O(logN), 20.36%, ok
    int findNthDigit(int n) {
        int len = 1;
        long count = 9;
        while(n > len * count){
            n -= len * count;
            count *= 10;
            len += 1;
        }
        int num = pow(10, len - 1) + (n - 1) / len;
        string s = to_string(num);
        return s[(n - 1) % len] - '0'; // bug: forget to convert to int
    }
};
