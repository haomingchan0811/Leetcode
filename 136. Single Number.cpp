#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Hash map O(n) space, easy to implement
int singleNumber(vector<int>& nums) {
	unordered_map<int, int> element;
	for(int i = 0; i < nums.size(); i ++){
		int temp = nums[i];
		if(element.count(temp) == 0)
			element[temp] = 1;
		else
			element.erase(temp);
	}
	auto it = element.begin();
	return it -> first;
}
*/

// // bit manipulation: O(N), 47.21%, ok
// int singleNumber(vector<int>& nums) {
//     int ans = 0;
//     for(auto i: nums) ans ^= i;
//     return ans;
// }

	// The trick is A ^ B ^ A = B, and XOR 符合交换律
    // bit manipulation (22 ms): using XOR to eliminate even duplicates, without extra space
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] ^= nums[i - 1];
        }
        return nums[nums.size() - 1];
    }

};


int main(){
	// default test case
	int testcase[5] = {1,2,2,1,3};
	vector<int> nums;
	for(int i = 0; i < 5; i ++){
		nums.push_back(testcase[i]);
	}

	cout << singleNumber(nums);
}
