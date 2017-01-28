class Solution {
public:
    // // O(N): TLE or overflow
    // int trailingZeroes(int n) {
    //     if(!n) return 0;
    //     if(n < 0) n = -n;
    //     long long factorial = 1;
    //     while(n){
    //         factorial *= n;
    //         n--;
    //     }
    //     cout << factorial << endl;
    //     int count = 0;
    //     while(factorial % 10 == 0){
    //         count++;
    //         factorial /= 10;
    //     }
    //     return count;
    // }

    // // O(N): TLE, did not pass large number case
    // int trailingZeroes(int n) {
    //     if(!n) return 0;
    //     if(n < 0) n = -n;
    //     int num2 = 0, num5 = 0;
    //     while(n){
    //         int temp = n;
    //         while(!(temp % 2)) {num2++; temp /= 2;}
    //         while(!(temp % 5)) {num5++; temp /= 5;}
    //         n--;
    //     }
    //     return min(num2, num5);
    // }

    // only counts the number of 5 as 2 is always ample
    // O(log_5(N)): ok
    int trailingZeroes(int n) {
        if(!n) return 0;
        if(n < 0) n = -n;
        int numOf5 = 0;
        while(n){
            n /= 5;
            numOf5 += n;
        }
        return numOf5;
    }
};
