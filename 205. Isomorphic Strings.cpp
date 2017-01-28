#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution {
public:
    // using unordered_map: 32ms
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;
        int len = s.length();
        for(int i = 0; i < len; i ++){
            char temp_s = s[i];
            char temp_t = t[i];
            if(map_s.count(temp_s) == 0 && map_t.count(temp_t) == 0){    // record the new pair
                map_s[temp_s] = temp_t;
                map_t[temp_t] = temp_s;
            }
            else
                if(map_s[temp_s] != temp_t || map_t[temp_t] != temp_s) // conflict match
                    return false;
        }
        return true;
    }

    // using array: 8ms
    bool isIsomorphic(string s, string t){
        if(s.length() != t.length())
            return false;
        char as[200] = {};
        char at[200] = {};  // bug: char does not limited to letters.
        int len = s.length();
        for(int i = 0; i < len; i ++){
            char temp_s = s[i];
            char temp_t = t[i];
            if(as[temp_s] != at[temp_t])
                return false;
            as[temp_s] = i + 1;     // sign the pair to the same index.
            at[temp_t] = i + 1;     // bug: 未定义的数组全部初始化为0，所以小心i = 0
        }
        return true;
    }
};

int main(){
	string s = "11";
	string t = "21";
	Solution sol;
	cout << sol.isIsomorphic(s, t) << endl;
}
