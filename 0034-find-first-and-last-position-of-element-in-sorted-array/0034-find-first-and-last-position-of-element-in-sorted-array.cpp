class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        //will calculate the lower limit
        int low1 = 0;
        int high1  = n-1;
        int lower = -1;

        while(low1 <= high1){
            int mid = low1 + (high1 - low1)/2;
            if(nums[mid] == target){
                lower = mid;
                high1 = mid -1;
            }
            else if(nums[mid] > target){
                high1 = mid - 1;
            }
            else{
                low1 = mid + 1;
            }
        }

        int low2 = 0;
        int high2 = n -1;
        int higher = -1;

        while(low2 <= high2){
            int mid = low2 + (high2 - low2)/2;
            if(nums[mid] == target){
                higher = mid;
                low2 = mid + 1;
            }
            else if(nums[mid] > target){
                high2 = mid - 1;
            }
            else{
                low2 = mid + 1;
            }
        }


        return {lower , higher};

        
        
    }
};