class Solution {
public:
    // sort: O(N2)time, O(N)space, 9.55%
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ret;
        if(nums.empty()) return ret;
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end(), cmp);
        for(int i = 0; i < nums.size(); i++){
            int rank = 0;
            while(nums1[rank] != nums[i]) rank++;
            switch(rank){
                case 0:
                    ret.push_back("Gold Medal");
                    break;
                case 1:
                    ret.push_back("Silver Medal");
                    break;
                case 2:
                    ret.push_back("Bronze Medal");
                    break;
                default:
                    ret.push_back(to_string(rank + 1));
            }
        }
        return ret;
    }

    static bool cmp(int a, int b){
        return a > b;
    }

    // sort: O(NlogN)time, O(N)space, 60.8%
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ret(nums.size(), "");
        if(nums.empty()) return ret;
        unordered_map<int, string> rank = {{0,"Gold Medal"}, {1,"Silver Medal"}, {2,"Bronze Medal"}};
        for(int i = 3; i < nums.size(); i++)
            rank[i] = to_string(i + 1);

        vector<pair<int, int>> p;
        for(int i = 0; i < nums.size(); i++)
            p.push_back({nums[i], i});
        sort(p.begin(), p.end(), myCmp);  // can be replaced by a priority queue
        for(int i = 0; i < p.size(); i++)
            ret[p[i].second] = rank[i];
        return ret;
    }

    static bool myCmp(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};
