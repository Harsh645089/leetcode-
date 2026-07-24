class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bought = false;
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for(int i = n - 1  ; i >= 0 ; i--){
            curr[0] = max(next[1] - prices[i] , next[0]);
            curr[1] = max(next[1] , prices[i]);
            swap(next , curr);
        }

        return next[0];

    }
};