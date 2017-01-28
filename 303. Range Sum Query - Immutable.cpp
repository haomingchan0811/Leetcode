#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class NumArray {
public:
    // 30ms
    // NumArray(vector<int> &nums) {
    //     sum.push_back(0);  // initial value
    //     for(int i = 0; i < nums.size(); i ++){
    //         sum.push_back(nums[i] + sum.back());
    //     }
    // }

    // partial_sum function: 28ms
    NumArray(vector<int> &nums) {
        sum.resize(nums.size() + 1, 0); // resize:http://www.cplusplus.com/reference/vector/vector/resize/
        // potential bug: sum.begin()+1 indicate that sum[1] is the first number.
        partial_sum(nums.begin(), nums.end(), sum.begin() + 1);
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }

private:
    vector<int> sum;
};


int main(){
    int test[6] = {-2, 0, 3, -5, 2, -1};
    vector<int> sum(test, test + 6);
    NumArray numarrays(sum);
    cout << numarrays.sumRange(0, 5);
}
