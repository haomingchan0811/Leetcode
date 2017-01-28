class Solution {
public:
    // brute force: O(N) time and space, 6.88%, ok
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        if(!digits.size()) return ans;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            ans.push_back((carry + digits[i]) % 10);
            carry = (carry + digits[i]) / 10;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // O(N) time and O(1) space: 6.88%, ok
    // this problem is a special case of adding only 1, so no need to apply the regular addition process
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0 && carry; i--){  // key: "&&carry"
            digits[i] = (digits[i] + 1) % 10;
            carry = (digits[i] == 0);
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
