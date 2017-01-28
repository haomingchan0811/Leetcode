#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    // // sort: O(NlogN) time without extra space, 91.01%, ok
     bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] == nums[i - 1])
                return true;
        return false;
     }

    // hashTable: O(N) time and space, 71.78%, ok
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> flag;
        for(int i = 0; i < nums.size(); i++)
            if(flag.count(nums[i])) return true;
            else flag[nums[i]] = 1;
        return false;
    }

    /*  For certain test cases with not very large N, the runtime of hashtable method can be slower than sort method.
        The reason is hash table has some overhead in maintaining its property.
        Real world performance can be different from what the Big-O notation says.
        The Big-O notation only tells us that for sufficiently large input, one will be faster than the other.
        Therefore, when N is not sufficiently large, an O(n) algorithm can be slower than an O(nlogn) algorithm. */
};

int main(){
	int testcase[] = {1,2,3,4,5,1};
	vector<int> test;
	for(int i = 0; i < sizeof(testcase) / sizeof(int); i ++){
		test.push_back(testcase[i]);
	}
	if(containsDuplicate(test))
		cout << "true";
}
