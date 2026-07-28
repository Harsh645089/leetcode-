class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double ans = INT_MIN;
        double sum = 0;
        
        while(i < n && j < n){

            sum += nums[j];

            if(j - i + 1 == k){
                ans = max(ans , sum/k);// jab bhi decimal main answer chahiye tab ya toh denominator ka double ya float kardo ya numerator ka kardo ans decimal amin milega
                sum -= nums[i];
                i++;
                j++;
                
            }
            else{
                j++;
            }
            
        }

        return ans;
    }
};