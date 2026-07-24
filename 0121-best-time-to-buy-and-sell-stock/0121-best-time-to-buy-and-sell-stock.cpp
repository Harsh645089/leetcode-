class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bought = false;
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        //curr[0] mean i don;t have anything till now and now i need to buy so i will use currbuy for this and currsell for curr[1] bcz i have bought something that i need to see

        //next[0] means i have nothing  so i will buy si nextbuy for this and next[1] = nextsell

        int nextbuy = 0;
        int nextsell = 0; 
        int currbuy = 0;
        int currsell = 0;

        for(int i = n - 1  ; i >= 0 ; i--){
            currbuy = max(nextsell - prices[i] , nextbuy);
            currsell = max(nextsell , prices[i]);
            nextbuy = currbuy;
            nextsell = currsell;
        }

        return nextbuy;

    }
};