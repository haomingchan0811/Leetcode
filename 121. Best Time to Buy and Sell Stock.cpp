class Solution {
public:
// // O(N2): TLE, didn't pass the large data case
    // int maxProfit(vector<int>& prices) {
    //     int profit = 0;
    //     for(int i = 0; i < prices.size(); i++){
    //         for(int j = i + 1; j < prices.size(); j++){
    //             if(prices[j] - prices[i] > profit)
    //                 profit = prices[j] - prices[i];
    //         }
    //     }
    //     return profit;
    // }

    // brute force: O(N)time, O(1)space, 44.31%, ok
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int minP = prices[0], ret = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            ret = max(ret, prices[i] - minP);
            minP = min(minP, prices[i]);
        }
        return ret > 0? ret: 0;
    }
};
