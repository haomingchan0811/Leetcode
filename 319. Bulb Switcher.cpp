class Solution {
public:
    // // brute force: O(N2) time and O(N) space, TLE for large data
    // int bulbSwitch(int n) {
    //     if(!n) return 0;
    //     int ret = 0;
    //     vector<int> bulb(n, 1);
    //     for(int i = 1; i < n; i++){
    //         ret += bulb[i - 1];
    //         for(int j = i; j < n; j += i + 1){
    //             if(bulb[j]) bulb[j] = 0;
    //             else bulb[j] = 1;
    //         }
    //     }
    //     return ret + bulb[n - 1];
    // }

    // answer == # square number: O(logN), 7.62%, ok
    int bulbSwitch(int n) {
        if(!n) return 0;
        int ret = 0;
        for(int i = 1; i * i <= n; i++)
            ret++;
        return ret;
    }

    // even conciser: 7.62%, ok
    int bulbSwitch(int n) {
        if(!n) return 0;
        return sqrt(n);
    }

};
