class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int allNumberXor = 0;
        if(n%4 == 0) allNumberXor = n;
        if(n%4 == 1) allNumberXor = 1;
        if(n%4 == 2) allNumberXor = n + 1;
        if(n%4 == 3) allNumberXor = 0;

        int ans = allNumberXor ;
        for(auto num : nums){
            ans = ans ^ num;
        }

        return ans;
    }
};