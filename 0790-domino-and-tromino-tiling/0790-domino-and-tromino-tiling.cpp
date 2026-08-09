class Solution {
public:
    const long long mod = 1e9 + 7;

    long long solve(int i, int n, bool empty, vector<vector<int>> &dp) {

        // Reached the end
        if (i == n) {
            return dp[empty][i] = empty ? 1 : 0;
        }


        if(dp[empty][i] != -1){
            return dp[empty][i] ;
        }

        long long ans = 0;

        if (empty) {

            // 1. Vertical domino
            ans += solve(i + 1, n, true , dp);

            // 2. Two horizontal dominoes
            if (i + 1 < n) {
                ans += solve(i + 2, n, true , dp); //as i +1 is the idx where we will gonna add new a domino
            }

            // 3. Tromino - orientation 1
            ans += solve(i + 1, n, false , dp);

            // 4. Tromino - orientation 2
            ans += solve(i + 1, n, false , dp);

        } 
        else {

            //as the current idx is partially filled so we can add a horizontal domino there and the nex i + 1 will be partailly filled
            ans += solve(i + 1, n, false , dp);


            //as this one is partially filled so we can put a tomino here and can move i + 2  that is fully empty
            if (i + 1 < n) {
                //i +1 < n because i + 1 is the idx which is needed to place the tromino
                ans += solve(i + 2, n, true , dp);
            }
        }

        return dp[empty][i] = ans % mod;
    }

    int numTilings(int n) {
        vector<vector<int>> dp(2 , vector<int>(n+ 1 , -1));
        
        return solve(0, n, true , dp);
    }
};