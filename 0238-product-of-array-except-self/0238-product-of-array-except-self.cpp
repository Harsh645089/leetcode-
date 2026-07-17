class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftproduct(n);
        vector<int> rightproduct(n);

        //oth element ke left 
        leftproduct[0] = 1;

        for(int i = 1 ; i < n ; i++){
            leftproduct[i] = leftproduct[i-1] * nums[i-1];
        }

        int rp = 1;

        for(int i = n - 1 ; i >= 0 ; i--){
            leftproduct[i] = leftproduct[i] * rp;
            rp = rp * nums[i] ;
        }

        return leftproduct;



    }
};