class Solution {
public:
    // two pointers: O(N), 9.27%, ok
    bool isStrobogrammatic(string num) {
        if(num.empty()) return true;
        unordered_map<char, char> dict = {{'6','9'}, {'0','0'}, {'1','1'}, {'8','8'}, {'9','6'}};
        int head = 0, tail = num.size() - 1;
        while(head <= tail){
            if(dict.count(num[head]) && dict[num[head]] == num[tail]){
                head++; tail--;
            }
            else return false;
        }
        return true;
    }

    // STL: O(N), 9.27%, ok
    bool isStrobogrammatic(string num) {
        if(num.empty()) return true;
        string test = "696 88 11 00";
        int head = 0, tail = num.size() - 1;
        string str1, str2;
        while(head <= tail){
            if(test.find(string(1, num[head]) + string(1, num[tail])) != string::npos){ // bug: num[head]+num[tail]
                head++; tail--;
            }
            else return false;
        }
        return true;
    }
};
