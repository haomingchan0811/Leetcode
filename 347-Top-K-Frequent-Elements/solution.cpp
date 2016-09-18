class Solution {
public:
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
    }
};