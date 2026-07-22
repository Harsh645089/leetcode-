class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        bool bought = false;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 , 0)); //one extra space for the base case

        for(int i = n-1 ; i >= 0 ; i--){
            //as i know the last state that is my base case

            int skip_buy = dp[i+1][0];
            int buy = dp[i+1][1] - prices[i] - fee;
            dp[i][0] = max(skip_buy  , buy);

            int skip_sell = dp[i+1][1];
            int sell = dp[i+1][0] + prices[i];
            dp[i][1] = max(skip_sell , sell);
        }

        return dp[0][0];

        
    }
};