class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //this is something crazy
        int n = nums.size();
        int low = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int high = 0 ; high < n ; high++){
            //this high will help me to find the prefix sum and also help me to the finf the first window that have sum >= target and then i will start shrinking the window until the conditon valid 

            sum += nums[high];

            while(sum >= target){
                //i got the window whose sum >= target so now let's shrink it and see till when this condition stays 
                ans = min(ans , high - low + 1);

                sum -= nums[low];

                low++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};