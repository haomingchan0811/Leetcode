#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // hashtable: 19ms
    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     unordered_map<int, int> add;    // store the complement of the member
    //     vector<int> ret;
    //     int len = numbers.size();
    //     bool found = false;
    //     for(int i = 0; i < len && (!found); i ++){
    //         int imp = target - numbers[i];
    //         unordered_map<int, int>::iterator it = add.begin();
    //         while(it != add.end()){
    //             if(it->first == numbers[i]){
    //                 ret.push_back(it->second);
    //                 ret.push_back(i + 1);
    //                 found = true;
    //                 break;
    //             }
    //             it ++;
    //         }
    //         add[imp] = i + 1;
    //     }
    //     return ret;
    // }

    // Two Pointers: 6ms
    vector<int> twoSum(vector<int>& numbers, int target){
        int low = 0, high = numbers.size() - 1;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target) break;
            else if(sum < target) low += 1;
            else high -= 1;;
        }
        vector<int> ans(1, low + 1);
        ans.push_back(high + 1);
        return ans;
    }
};

int main(){
	// default test case
	int test[4] = {2, 7, 11, 15};
    vector<int> testCase(test, test+4);
	int target = 9;
    Solution sol;
	testCase = sol.twoSum(testCase, target);
    for(auto i : testCase)
        cout << i << "-";
	return 0;
}
