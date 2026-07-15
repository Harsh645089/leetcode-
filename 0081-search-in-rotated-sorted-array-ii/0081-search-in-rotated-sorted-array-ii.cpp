class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ; 
        int high  = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return true;

            //to remove the duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]){
                //means left is sorted
                if(nums[low] <= target && target < nums[mid]){
                    // nums[mid] == target this cannot be happen as we have checked above
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                //right half is sorted
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};