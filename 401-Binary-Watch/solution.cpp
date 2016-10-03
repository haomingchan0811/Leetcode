class Solution {
public:
    // bitset:
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


    // //calculate the number of bits that has value one
    // int numOfBits(int num){
    //     int count = 0;
    //     while(num){
    //         count ++;
    //         num = num & (num - 1);
    //     }
    //     return count;
    // }
    // // brute-force: 0ms
    // vector<string> readBinaryWatch(int num) {
    //     vector<string> ans;
    //     for(int i = 0; i <= 11; i++){
    //         int complement = num - numOfBits(i);
    //         if(complement >= 0){
    //             for(int j = 0; j <= 59; j++){
    //                 if(complement == numOfBits(j)){
    //                     string min = (j < 10) ? "0" + to_string(j) : to_string(j);
    //                     ans.push_back(to_string(i) + ":" + min);
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};