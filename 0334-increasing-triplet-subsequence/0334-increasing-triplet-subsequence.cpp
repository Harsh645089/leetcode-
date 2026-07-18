class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int first = INT_MAX;
        int second = INT_MAX;

        for(auto num : nums){
            if(num <= first){
                first = num; //getting the smallest first untill i got larger than the first
            }
            else if(num <= second){
                second = num;
            }
            else{
                return true;
            }
        }

        return false;
    }
};