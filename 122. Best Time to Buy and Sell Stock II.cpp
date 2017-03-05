class Solution {
public:
    // Greedy: looking for consecutive Peak and Valley
    // O(N)time, O(1)space, 38.12%, ok
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ret = 0, i = 1;
        int valley = prices[0], peak = INT_MIN;
        while(i < prices.size()){
            while(i < prices.size() && prices[i] <= prices[i - 1])
                valley = prices[i++];
            while(i < prices.size() && prices[i] > prices[i - 1])
                peak = prices[i++];
            if(peak != INT_MIN && valley != INT_MIN) {
                ret += peak - valley;
                peak = valley = INT_MIN;
            }
        }
        return ret;
    }

    // Greedy: add difference whenever i+1 is larger than i
    // O(N)time, O(1)space, 38.12%, ok
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ret = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1])
                ret += prices[i] - prices[i - 1];
        }
        return ret;
    }
};
