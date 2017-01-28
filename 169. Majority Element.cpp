#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // hashtable, O(N), 42.57%
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> record;
        int size = nums.size();
        for(auto n: nums) record[n] += 1;
        auto it = record.begin();
        for(it; it != record.end(); it++){
            if(it->second > floor(size * 1.0 / 2))
                return it->first;
        }
        return 0;
    }

    // Moore Voting Algorithm, O(N) time, O(1) space, 69.36%, ok
    int majorityElement(vector<int>& nums) {
        int major, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                major = nums[i];
                count = 1;
            }
            else if(nums[i] == major) count += 1;
            else count -= 1;
        }
        return major;
    }

    // sort and return the middle element, O(NlogN)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[(nums.size() - 1) / 2];
    }

};
int main(){
	// default test case
	int case1[] = {1, 2, 2, 2, 1};
	vector<int> nums1;
	for(int i = 0; i < 5; i ++){
		nums1.push_back(case1[i]);
	}
	cout << majorityElement(nums1);
}
