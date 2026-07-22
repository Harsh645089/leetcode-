class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        bool bought = false;
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for(int i = n-1 ; i >= 0 ; i--){
            //as i know the last state that is my base case

            int skip_buy = next[0];
            int buy = next[1] - prices[i] - fee;
            curr[0] = max(skip_buy  , buy);

            int skip_sell = next[1];
            int sell = next[0] + prices[i];
            curr[1] = max(skip_sell , sell);

            swap(next , curr);
        }

        return next[0];

        
    }
};