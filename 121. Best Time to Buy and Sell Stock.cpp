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

    // O(N): 47.21% ,ok
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0; // bug: corner case
        int profit = 0, minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};
