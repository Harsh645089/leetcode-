class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;

        while(low < high){
            int mid = low + (high - low)/2;

            if(mid + 1 <= n -1 && arr[mid+1] >= arr[mid]){
                ans = mid + 1;
                low  = mid + 1;
            }
            else if(mid -1 >= 0 && arr[mid-1] > arr[mid]){
                ans = mid -1;
                high = mid -1;
            }
            else{
                //means bith are small means we have found the peak
                ans = mid;
                break;
            }
        }

        return ans;

    }
};