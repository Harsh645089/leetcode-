class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin() , nums.end());

        int triples_count = 0;

        for(int k = n-1 ; k >= 0 ; k--){
            int i = 0;
            int j = k-1; //means we have selected the kth and now trying to find the valid ith and jth terms

            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    //means i , i+1 , i+2.......jth tak sab valid hai as if i incease i term then the sum increase not decrease;
                    triples_count += j - i;
                    j--; //to find the new i and j pair and decrease the sum and use i terms to increase it so that we can get more valid pairs
                }
                else{
                    i++; //increase the sum as it is sorted
                }
            }
        }

        return triples_count;
    }
};