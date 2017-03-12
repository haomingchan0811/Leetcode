#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <valarray>
using namespace std;

class Solution {
public:
    // bucket sort: 36ms
    vector<int> topKFrequent(vector<int>& nums, int k){
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i ++){
            freq[nums[i]] ++;
        }
        // the frequency of a number can not exceec nums.size()
        vector<vector<int> > buckets(nums.size() + 1);    // number of vectors = nums.size()
        for(auto num: freq){
            int index = num.second;
            buckets[index].push_back(num.first);
        }
        int count = 0;
        for(int i = nums.size(); i >= 0; i --){
            for(auto b: buckets[i]){
                if(count < k){
                    ans.push_back(b);
                    count ++;
                }
                else break;
            }
        }
        return ans;
    }

    // hashmap & heap: O(NlogN)time, O(1) space, 57.76%, ok
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        for(auto n: nums) cnt[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        for(auto p: cnt) pq.push(p);
        for(int i = 0; i < k; i++){
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }

    // hashmap & sort: O(NlogN)time, O(1) space, 78.60%, ok
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        for(auto n: nums) cnt[n]++;
        vector<pair<int, int>> vec;
        for(auto p: cnt) vec.push_back(p);
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){return a.second > b.second;});
        for(int i = 0; i < k; i++)
            ret.push_back(vec[i].first);

        return ret;
    }
};

int main(){
    int test[7] = {4,1,-1,2,-1,2,3};
    vector<int> t(test, test + 7);
    Solution sol;
    int k = 2;
    t = sol.topKFrequent(t, k);
    for(int i = 0; i < k; i ++)
        cout << t[i] << endl;
}
