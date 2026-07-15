class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  n = nums.size();

        int low = 0;
        int high = n -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                return mid;
            }
            

            if(nums[low] <= nums[mid]){
                //left part is sorted
                if(nums[low] <= target && target <= nums[mid]){
                    //within sorted range
                    high = mid;
                }
                else{
                    //not in sorted half
                    low = mid + 1;
                }
            }
            else{
                //right part is sorted
                if(nums[mid] <= target && target <= nums[high]){
                    //within the right sorted half
                    low = mid;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};