#include <iostream>
#include <vector>
#include <bitset>
#include <string>

class Solution {
public:
    // A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

    // bitset: 0ms，O(1) time & space, 40.87%, ok
    vector<string> readBinaryWatch(int num){
        vector<string> ans;
        for(int i = 0; i < 12; i++){
            bitset<4> hour (i);
            int bit_h = hour.count();
            if(bit_h <= num){
                for(int j = 0; j < 60; j++){
                    bitset<6> min (j);
                    if(bit_h + min.count() == num)
                        ans.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
                }
            }
        }
        return ans;
    }

    // bitset, more elegant: O(1) time & space, 40.87%, ok
    vector<string> readBinaryWatch(int num) {
        if(!num) return vector<string>(1, "0:00");
        vector<string> ret;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                bitset<10> bit((i << 6) | j); // this is brilliant
                if(bit.count() == num)
                    ret.push_back(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
            }
        }
        return ret;
    }

    //calculate the number of bits that has value one
    int numOfBits(int num){
        int count = 0;
        while(num){
            count ++;
            num = num & (num - 1); // trick: eliminate the rightmost 1
        }
        return count;
    }
    // brute-force: 0ms
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i = 0; i <= 11; i++){
            int complement = num - numOfBits(i);
            if(complement >= 0){
                for(int j = 0; j <= 59; j++){
                    if(complement == numOfBits(j)){
                        string min = (j < 10) ? "0" + to_string(j) : to_string(j);
                        ans.push_back(to_string(i) + ":" + min);
                    }
                }
            }
        }
        return ans;
    }
};
