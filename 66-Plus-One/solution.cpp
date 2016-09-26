class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator it = digits.end() - 1; 
        if(*it == 9){
            bool carry = 1;     // carry over digit
            while(it != digits.begin() - 1){
                if(carry) *it += 1;
                if(*it == 10){
                    *it = 0;
                    carry = 1;
                }
                else carry = 0;
                it --;
            }
            if (*digits.begin() == 0){      // bug: whether the most significant digit has carry over digit
                vector<int> ans(1, 1);
                int i = 0;
                while(i < digits.size()){
                    ans.push_back(digits[i]);
                    i ++;
                }
                return ans;
            }
        }
        else *it += 1;
        return digits;
    }
};