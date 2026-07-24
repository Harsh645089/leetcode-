class Solution {
public:
    int solve(vector<int> &prices , int n , int bought , int i , vector<vector<int>> &dp){
        if(i >= n) return 0; //now agar bought hai toh can't sell it or if not bought yet then cannot bought

        if(dp[i][bought] != -1) return dp[i][bought];

        if(bought == true){
            return dp[i][bought] = max(prices[i]  , 
                        solve(prices , n , true ,i+1 , dp));
        }
        else{
            return dp[i][bought] = max(solve(prices , n , true , i+ 1 , dp) - prices[i] , 
                        solve(prices , n , false , i+ 1 , dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bought = false;
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return solve(prices , n , bought , 0 , dp);

    }
};