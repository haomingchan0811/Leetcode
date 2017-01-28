#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    // istringstream without stack: 25.19%, string copy takes more time
    void reverseWords(string &s){
        istringstream cut(s);
        string temp;
        s = "";
        cut >> s;
        while(cut >> temp)
            s = temp + " " + s;
    }


    // brute-force, reverse each word and finally reverse whole string
    // O(N) time, O(1) space: 73.63%, ok
    void reverseWords(string &s) {
        int i = 0, j = 0, len = s.size();
        int head, wordCnt = 0;
        while(1){
            while(i < len && s[i] == ' ') i++; // eliminate preceding zeors
            if(i == len) break;
            if(wordCnt++) s[j++] = ' ';
            head = j;
            while(i < len && s[i] != ' ') s[j++] = s[i++]; // move in place
            reverseString(s, head, j - 1); // reverse a single word
        }
        s.resize(j);
        reverseString(s, 0, j - 1);
    }

    void reverseString(string& s, int i, int j){
        while(i < j){
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }

    // // Brute force: 9ms
    // void reverseWords(string &s) {
    //     stack<string> cache;
    //     string temp = "";
    //     for(int i = 0; i < s.size(); i++){
    //         if(s[i] != ' ')
    //             temp += s[i];
    //         else if(temp != ""){
    //             cache.push(temp);
    //             temp = "";
    //             cout << temp << endl;
    //         }
    //     }
    //     if(temp != "") cache.push(temp); // bug: Eg:input format "  hi"
    //     string ans = "";
    //     bool isFirstWd = true;
    //     while(!cache.empty()){
    //         if(isFirstWd){
    //             ans += cache.top();
    //             isFirstWd = false;
    //         }
    //         else
    //             ans += " " + cache.top();
    //         cache.pop();
    //     }
    //     s = ans;
    // }
};

int main(){
    Solution sol;
    string s = " ";
    sol.reverseWords(s);
}
