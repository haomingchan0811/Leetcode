class Solution {
public:
    // dynamic programming: O(N)time & space,
    int minCost(vector<vector<int>>& costs) {
        int num_house = costs.size();
        if(!num_house) return 0;
        vector<vector<int>> ret(num_house, vector<int>(3, 0));
        for(int i = 0; i < 3; i++)
            ret[0][i] = costs[0][i];  // base case
        for(int i = 1; i < num_house; i++){
            ret[i][0] = min(ret[i - 1][1], ret[i - 1][2]) + costs[i][0];
            ret[i][1] = min(ret[i - 1][0], ret[i - 1][2]) + costs[i][1];
            ret[i][2] = min(ret[i - 1][0], ret[i - 1][1]) + costs[i][2];
        }
        int minCost = INT_MAX;
        for(int i = 0; i < 3; i++)
            minCost = min(minCost, ret[num_house - 1][i]);
        return minCost;
    }

    // dynamic programming: O(N)time, O(1)space, 46.88%
    int minCost(vector<vector<int>>& costs) {
        int num_house = costs.size();
        if(!num_house) return 0;
        vector<int> cost = costs[0]; // base case
        for(int i = 1; i < num_house; i++){
            int c0 = cost[0], c1 = cost[1], c2 = cost[2];
            cost[0] = min(c1, c2) + costs[i][0];
            cost[1] = min(c0, c2) + costs[i][1];
            cost[2] = min(c0, c1) + costs[i][2];
        }
        return *min_element(cost.begin(), cost.end());
    }
};
