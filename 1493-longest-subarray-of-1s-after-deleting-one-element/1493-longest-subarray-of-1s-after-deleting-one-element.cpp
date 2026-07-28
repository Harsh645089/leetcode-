class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        bool Delete = false;
        int count = 0;
        int ans = INT_MIN;

        while(i < n && j < n){
            if(nums[j] == 1){
                j++;
                count++;
            }
            else if(Delete == false){
                j++;
                Delete = true;
            }

            else{
                ans = max(ans , count);
                if(nums[i] == 0) Delete = false;
                else count--;
                i++;
            }
        }

        if(j == n){
            if(count > ans ){
                if(Delete == false) ans = count -1;
                else ans = count;
                
            }

        }

        return ans;
    }
};