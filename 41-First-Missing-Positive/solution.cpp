class Solution {
public:
    // brute-force using set ans priority_queue: 6ms
    int firstMissingPositive(vector<int>& nums) {
        // bug scenario: empty vector
        if(nums.empty()) return 1;
        if(nums.size() == 1) return nums[0] == 1 ? 2 : 1; // bug scenario: if vector contains a single number
        priority_queue<int> que;
        set<int> s;
        for(auto num: nums)
            if(num >= 0) s.insert(num);
        bool zero = false;      // whether 0 exists or not
        for(auto num: s){
            if(num == 0) zero = true;
            if(num >= 0) que.push(num);
        }
        // if 0 is not in que, add 0
        if(!zero) que.push(0);

        int cur = que.top() - 1;
        int ans = que.top() + 1;    // bug: if input is a consecutive list of num, should return (largest num + 1)
        que.pop();
        while(!que.empty()){
            int top = que.top();
            // printf("%d %d\n", top, cur);
            if(cur != top){
                ans = top + 1;
                // cout << ans << endl;
            }
            cur = top - 1;
            que.pop();
        }
        return ans;  
    }
};
