class Solution {
public:
    //calculate the number of bits that has value one
    int numOfBits(int num){
        int count = 0;
        while(num){
            count ++;
            num = num & (num - 1);
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