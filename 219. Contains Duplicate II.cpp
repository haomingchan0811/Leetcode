#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in 
// the array such that nums[i] = nums[j] and the difference between i and j is at most k

/* unordered_map
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> hash_map;
	for(int i = 0; i < nums.size(); i ++){
		int current = nums[i];
		if(!hash_map.count(current))
			hash_map[current] = i;
		else{
			if(i - hash_map[current] <= k)
				return true;
			else    // bug: should update the indice in case the rest of the array accords 
				hash_map[current] = i;
		}
	}
	return false;
} */
	
// unordered_set 
bool containsNearbyDuplicate(vector<int>& nums, int k){
	unordered_set<int> s;
	if (k <= 0) 
		return false;
	// if (k >= nums.size()) k = nums.size() - 1;
   
	for (int i = 0; i < nums.size(); i++){
		// maintain a set s which contain unique values from nums[i - k] to nums[i - 1]
		if (i > k) 
			s.erase(nums[i - k - 1]);
			
		// if nums[i] is in set s then return true, else update the set.
		if (s.count(nums[i]))
			return true;
		s.insert(nums[i]);
	}
	return false;
}

int main(){
	// default test case
	vector<int> testCase;
	int test[4] = {1, 0, 1, 1};
	for(int i = 0; i < sizeof(test); i ++)
		testCase.push_back(test[i]);
	int k = 1;

	cout << containsNearbyDuplicate(testCase, k);
}
