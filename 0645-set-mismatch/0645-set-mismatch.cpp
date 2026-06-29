class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorOfAllNumbers ;
        if(n % 4 == 0) xorOfAllNumbers = n ;
        if(n % 4 == 1) xorOfAllNumbers = 1;
        if(n % 4 == 2) xorOfAllNumbers = n + 1;
        if(n % 4 == 3) xorOfAllNumbers = 0;

        int xorr = xorOfAllNumbers;

        for(auto num : nums){
            xorr = xorr ^ num;
        }

        //now xorr is the xor of the missing and the duplicate number only
        
        int rightmostActiveBit = (xorr & (xorr -1)) ^ xorr;
        int num1 = 0 ;
        int num2 = 0;

        for(auto num : nums){
            if((num & rightmostActiveBit) != 0){
                //means in nums this bit is active
                num1 = num1 ^ num;
            }
            else{
                num2 = num2 ^ num;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if((i & rightmostActiveBit) != 0){
                //means in nums this bit is active
                num1 = num1 ^ i;
            }
            else{
                num2 = num2 ^ i;
            }
        }

        //now i have both duplicate and missing but don't know which one is which ?

        for(auto num : nums){
            if(num == num1){
                return {num1 , num2};
            }
        }

        return {num2  , num1};
    }
};