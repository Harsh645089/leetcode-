class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = 1e9;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[low] <= nums[mid]){
                //means left part is sorted
                ans = min(ans , nums[low]);
                low = mid + 1; //bcz sorted range ka min le liye and now unsorted wale main dekhte hai
            }
            else {
                //right is sorted bcz the array is only rotated and sorted
                ans = min(ans , nums[mid]); //mis se aage sab increasing hi hai
                high = mid - 1;
            }
        }

        return ans;
    }
};