class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =  nums.size();
        vector<int> prefixsum(n ,0) ;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            prefixsum[i] = sum;
        }

        int ans_len = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            int low = i;
            int high = n-1;

            while(low <= high){
                int j = low +(high - low)/2;

                if(prefixsum[j] - prefixsum[i] + nums[i] >= target){
                    ans_len = min(ans_len , j - i + 1);
                    high = j -1;
                }
                else{
                    low = j + 1;
                }
            }
        }

        if(ans_len == INT_MAX) return 0;

        return ans_len;
    }
};