#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// unordered map to conduct hash map search
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> intersection;
	vector<int> ans;
	vector<int>::iterator it = nums1.begin();
	for(it; it != nums1.end(); it ++){
		if(intersection.count(*it) == 0)
			intersection[*it] = 1;
		else
			intersection[*it] += 1;
	}
	vector<int>::iterator it2 = nums2.begin();
	for(it2; it2 != nums2.end(); it2 ++){
		if(intersection.count(*it2) && (-- intersection[*it2] >= 0))
			ans.push_back(*it2);
	}
	return ans;
}

// sort and compare with Two Pointers
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	vector<int> ans;
	int len1 = nums1.size();
	int len2 = nums2.size();
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int i, j = 0;   // two pointers
	while(i < len1 && j < len2){
		int num1 = nums1[i];
		int num2 = nums2[j];
		if(num1 < num2)
			i ++;
		else if(num1 > num2)
			j ++;
		else{
			ans.push_back(num1);
			i ++;
			j ++;
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
	vector<int> ans = intersect(nums1, nums2);
	for(int i = 0; i < ans.size(); i ++){
		cout << ans[i] << endl;
	}
}
