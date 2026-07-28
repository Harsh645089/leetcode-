class Solution {
public:
    //note in variable length sliding window if the window become invalid then i need to shrink the window instead of restarting the window 
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int i = 0;
        int j = 0;
        int flips = k;
        while(i < n && j < n){
            if(nums[j] == 1 ){
                j++;
            }
            else if(flips != 0){
                j++;
                flips--;
            }
            else{
                //no flip left and not equal to 1 so need to end it
                ans = max(ans , j - i);
                if(nums[i] == 0) flips++; //as till now the window is not valid so i need to make it valid and i need to include this zero and for that i need to remove one zero so that's what i am doing here
                i++;
            }
        } 

        if(j == n) ans = max(ans , j - i);

        return ans ;
    }
};