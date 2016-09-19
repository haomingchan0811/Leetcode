class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // bug scenario: empty vector
        if(nums.empty()) return 1
        priority_queue<int> que;
        bool zero = false;      // whether 0 exists or not
        for(auto num: nums){
            if(num == 0) zero = true;
            if(num >= 0) que.push(num);
        }
        // if 0 is not in que, add 0
        if(!zero) que.push(0);

        int cur = que.top() - 1;
        int ans;
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
