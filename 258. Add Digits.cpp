#include <iostream>
using namespace std;

// brute force
int addDigits(int num) {
	if(num < 10) return num;
	int ans = 0;    // the sum of its digits
	while(num / 10){
		ans += num % 10;	// the right most digit
		num /= 10;
		// cout << ans << " " << num << endl;
	}
	ans += num;
	return addDigits(ans);
}

// Without loop/recursion, O(1) complexity
// referrece: digital root(checksum)
// https://en.wikipedia.org/wiki/Digital_root
// find pattern: O(1), 34.34%, ok
int addDigits(int num) {
	if(num == 0) return 0; // corner case
	int ans = num % 9;
	return ans == 0 ? 9 : ans;
}


int main(){
	// default test case
	int test = 38;
	cout << addDigits(test);
}
