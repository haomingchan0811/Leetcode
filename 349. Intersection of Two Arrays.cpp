#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* unorderd_hash_map
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> element;   // store the unique nums of the shorter vector into a hash map
	vector<int> ans;        // store the intersection of two arrays
	for(int i = 0; i < nums2.size(); i ++){
		// element.insert(pair<int, int>(nums2[i], 1));
		element[nums2[i]] = 1;
	}
	for(int j = 0; j < nums1.size(); j ++){
		if(element.find(nums1[j]) != element.end()){
			ans.push_back(nums1[j]);
			element.erase(nums1[j]);
		}
	}
	return ans;
}
*/

// unordered_set
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	unordered_set<int> s(nums1.begin(), nums1.end());
	vector<int> ans;
	for(int i = 0; i < nums2.size(); i ++){
		int temp = nums2[i];
//		if(s.find(temp) != s.end()){
		if(s.count(temp)){	// a positive count means it exits
			ans.push_back(temp);
			s.erase(temp);
		}
	}
	return ans;
}


int main(){
	// default test case
	int case1[] = {1, 2, 2, 1};
	int case2[] = {2, 2}; 
	vector<int> nums1;
	vector<int> nums2;
	for(int i = 0; i < 4; i ++){
		nums1.push_back(case1[i]);
	}
	for(int i = 0; i < 2; i ++){
		nums2.push_back(case2[i]);
	}
	vector<int> ans = intersection(nums1, nums2);
	for(int i = 0; i < ans.size(); i ++){
		cout << ans[i] << endl;
	}
}
