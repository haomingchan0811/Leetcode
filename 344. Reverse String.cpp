#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Brute Force Swap
string reverseString(string s){
	int length = s.length();
	string ans = "";
	int iterator = length - 1;
	for(int i = 0; i < length; i ++, iterator --)
		ans += s[iterator];
	return ans;
}
*/

/* stack */
string reverseString(string s){
	int length = s.length();
	stack<char> temp;
	for(int i = 0; i < length; i ++){
		temp.push(s[i]);
	}
	string answer = "";
	for(int i = 0; i < length; i ++){
		answer += temp.top();
		temp.pop();
	}
	return answer;
}

    // O(N) time O(1) space: 36.64%, ok
    string reverseString(string s) {
        int mid = (s.size() - 1) / 2;
        for(int i = 0; i <= mid; i++){
            int index = s.size() - 1 - i;
            char temp = s[index];
            s[index] = s[i];
            s[i] = temp;
        }
        return s;
    }

    // O(N) time O(1) space with more elegant way:
    string reverseString(string s) {
        int head = 0, tail = s.size() - 1;
        while(head <= tail){
            // swap(s[head++], s[tail--]); 4.13%
            char temp = s[tail]; // 11.73%
            s[tail] = s[head];
            s[head] = temp;
            head++, tail--;
        }
        return s;
    }

    // O(N) time and space: 24.01%
    string reverseString(string s) {
        string ans = "";
        for(int i = s.size() - 1; i >= 0; i--) ans += s[i];
        return ans;
    }
};

int main(){
	string temp = "hello";
	cout << reverseString(temp) << endl;
}
