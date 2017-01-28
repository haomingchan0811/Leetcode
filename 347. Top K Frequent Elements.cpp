#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <valarray>
using namespace std;

class Solution {
public:
    // priority_queue: 33ms
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i ++){
            freq[nums[i]] ++;
        }
        priority_queue<pair<int, int> > pq;
        for(unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
            pq.push(make_pair(it->second, it->first));
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }*/

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
