class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long  xorr = 0;
        for(auto num : nums){
            xorr = xorr ^ num;
        }

        long long rightmost  = (xorr & (xorr -1)) ^ xorr ;
        //it have only the right most bit of xorr as 1 else all are 0 and as this bit is 1 means both number are different at this bit so we can put them in different buckets

        int num1 = 0;
        int num2  = 0;

        for(auto num : nums){
            if((num  & rightmost) != 0){
                //means it's rightmost is active so put it in one bucket let is be num1
                num1 = num1 ^ num ;
                //xor will remove the same and which will lead to the only number that is one of the ans
            }
            else{
                num2 = num2 ^ num;
            }
        }

        return {num1 , num2};

    }
};