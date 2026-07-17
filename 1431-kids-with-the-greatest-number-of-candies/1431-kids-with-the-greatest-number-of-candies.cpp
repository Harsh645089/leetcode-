class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maximumNum = max_element(candies.begin() , candies.end())  - candies.begin();
        vector<bool> ans(n , false);
        for(int i = 0 ; i < n ; i++){
            if(candies[i] + extraCandies >= candies[maximumNum]){
                ans[i] = true;
            }
        }
        return ans;
    }
};