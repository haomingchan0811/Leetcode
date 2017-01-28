#include <iostream>
#include <cstring>
#include <stack>
#include <ctype.h>
using namespace std;

class Solution {
public:
    // Two pointers: 16ms
    bool isPalindrome(string s){
        int len = s.length();
        if(len == 0) return true;
        int start = 0, end = len - 1;
        while(start < end){
            while(!isalnum(s[start]) && start < end) start ++;
            while(!isalnum(s[end]) && start < end) end --;
            if(toupper(s[start]) != toupper(s[end]))
                return false;
            start ++;
            end --;
        }
        return true;
    }

    /*
    // shitty code: 16ms, accepted but have to implement my own function
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;     // a empty string is considered palindrome
        // bug: should chunk the string to eliminate all ilegal elements before judgement
        string sNew = "";
        for(char temp: s)
            if(isAlphanumeric(temp))
                sNew += temp;

        cout << sNew << endl;
        int len = sNew.length();
        if(len == 0)     // bug: empty string consists of blankd is considered palindrome
            return true;
        // Two pointers
        int left = 0;
        int right = len - 1;
        while(right > left && isSame(sNew[left], sNew[right])){
            cout << sNew[left] << " - " << sNew[right] << endl;
            if(right == left + 1) return true;
            left ++;
            right --;
        }
        if(left == right) return true;  // bug: 奇偶数长度的string判断条件
        return false;
    }

    // can be replaced by toupper() or tolower()
    bool isSame(char a, char b){
        int x = int(a);
        int y = int(b);
        if(x == y) return true;
        else if(x < 65 || y < 65) return false; // bug: 0和P的ASCII刚好差32(P=80, 0=48)
        else if ((x == y - 32) || (y == x - 32)) return true;
        return false;
    }
    // can be replaced by isalnum()
    bool isAlphanumeric(char x){
        if((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9') || (x >= 'A' && x <= 'Z'))
            return true;
        return false;
    }*/
};


int main(){
	// default test case
	Solution sol;
	string test1 = "A man, a plan, a canal: Panama";
    string test = "!!!!";   // bug testcase (no legal characters)
    string s1 = "0P";    // bug: 0和P的ASCII刚好差32(P=80, 0=48)
    string s= "Zeus was deified saw Suez.";
    cout << sol.isPalindrome(s) << endl;
}
