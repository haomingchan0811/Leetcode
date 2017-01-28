class Solution {
public:
    // // brute force: O(max(M, N)) time and space, 52.62%, ok
    // string addStrings(string num1, string num2) {
    //     string ret;
    //     // C++ bug: string.size() is unsigned type_t, 1 - 2 is undefined...
    //     int diff = abs(int(num1.size()) - int(num2.size())), carry = 0;
    //     if(num1.size() >= num2.size()){
    //         for(int i = num2.size() - 1; i >= 0; i--){
    //             int x1 = num1[i + diff] - '0', x2 = num2[i] - '0';
    //             ret += to_string((x1 + x2 + carry) % 10);
    //             carry = (x1 + x2 + carry) / 10;
    //         }
    //         for(int i = diff - 1; i >= 0; i--){
    //             int x = num1[i] - '0';
    //             ret += to_string((x + carry) % 10);
    //             carry = (x + carry) / 10;
    //         }
    //     }
    //     else{
    //         for(int i = num1.size() - 1; i >= 0 ; i--){
    //             int x1 = num1[i] - '0', x2 = num2[i + diff] - '0';
    //             ret += to_string((x1 + x2 + carry) % 10);
    //             carry = (x1 + x2 + carry) / 10;
    //         }
    //         for(int i = diff - 1; i >= 0; i--){
    //             int x = num2[i] - '0';
    //             ret += to_string((x + carry) % 10);
    //             carry = (x + carry) / 10;
    //         }
    //     }
    //     if(carry) ret += "1";
    //     reverse(ret.begin(), ret.end());
    //     return ret;
    // }

    // more elegant: O(max(M, N)) time and space, 52.62%, ok
    string addStrings(string num1, string num2) {
        string ret;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        for(; i >= 0 || j >= 0 || carry; i--, j--){
            int sum = carry;
            if(i >= 0) sum += num1[i] - '0';
            if(j >= 0) sum += num2[j] - '0';
            ret += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    // O(max(M, N)) time, O(1) space, 91.96%, ok
    // stop early to avoid unnecessary operations
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()) return addStrings(num2, num1);
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        for(; i >= 0 && (j >= 0 || carry); i--, j--){
            int sum = carry + (num1[i] - '0');
            if(j >= 0) sum += num2[j] - '0';
            num1[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        return (carry? "1":"") + num1;
    }
};
