class Solution {
public:
    int returnMaxProfit(int bought, vector<int> &prices , int fee   , int i , int totaldays , vector<vector<int>> &dp){
        if(i >= totaldays){
            return 0; //means now if i have bought something then i cannot sell it so this is my loss
        }

        if(dp[i][bought] != -1){
            return dp[i][bought];
        }
        

        if(bought == false){
            //not bought it yet
            return dp[i][bought] = max(returnMaxProfit(bought  , prices, fee, i+1 , totaldays , dp) , 
                        returnMaxProfit(true  , prices, fee, i+1 , totaldays , dp) - ( prices[i] + fee) );
        }
        
        else{
            //have bought the tock so now need to sell it

            return dp[i][bought] = max( prices[i] + returnMaxProfit(false, prices  , fee ,i+1 , totaldays , dp) , 
                                returnMaxProfit(bought , prices, fee, i+1 , totaldays , dp)) ;
            
            
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        bool bought = false;
        int totalDays = prices.size();
        vector<vector<int>> dp(totalDays , vector<int>(2 , -1));
        return returnMaxProfit(bought , prices , fee , 0 , totalDays , dp);
    }
};