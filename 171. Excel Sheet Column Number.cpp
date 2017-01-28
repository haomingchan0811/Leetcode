#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int titleToNumber(string s) {
	/* original thought
	int len = s.size();
	int ans = 0;    // don't forget to initialize
	// char类型存的是acsii码，可用int转化，string转char用s[]
	for(int i = len - 1, bitCount = 0; i >= 0; i --, bitCount ++){
		ans += (int(s[i]) - 64) * pow(26.0, bitCount * 1.0);
	}
	return ans;*/

	// more fluent thought
	int len = s.size(), ans = 0;
	for (int i = 0; i < len; i++)
		ans = ans * 26 + s[i] - 'A' + 1;
	return ans;
}

// O(N): 33.99%, ok
int titleToNumber(string s) {
	int ret = 0;
	for(int i = 0, exp = s.size() - 1; i < s.size(); i++, exp--)
		ret += (s[i] - 'A' + 1) * pow(26.0, exp);
	return ret;
}

int main(){
	// default test case
	string temp = "AB";
	cout << titleToNumber(temp);
}
