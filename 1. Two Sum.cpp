#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute Force
vector<int> twoSum_Brute_force(vector<int>& nums, int target) {
	vector<int> indice;
    for(int i = 0; i < nums.size(); i ++){
    	for(int j = i + 1; j < nums.size(); j ++){
    		if(nums[i] + nums[j] == target){
    			indice.push_back(i);
    			indice.push_back(j);
    			// cout << i << " " << j << endl;
    			return indice;
    		}
    	}
    }
	return indice;
}

// one pass hashtable: O(n), 67.01%
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	unordered_map<int, int> complement;
	for(int i = 0; i < nums.size(); i++){
		unordered_map<int, int>::iterator it = complement.find(nums[i]);
		if(it == complement.end())
			complement[target - nums[i]] = i;
		else{
			ans.push_back(it->second);
			ans.push_back(i);
		}
	}
	return ans;
}


int main(){
	// default test case
	vector<int> testCase;
	int test[4] = {2, 7, 11, 15};
	for(int i = 0; i < sizeof(test); i ++)
		testCase.push_back(test[i]);
	int target = 9;

	twoSum_Hash_map(testCase, target);
	return 0;
}
