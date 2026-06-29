class Solution {
public:
    int getSum(int a, int b) {

        int num1 = a;
        int num2 = b;

        int ans = 0;
        int carry = 0;

        for(int i = 0  ; i < 32 ; i++){

            int lastbitOfnum1 = num1 & 1;
            int lastbitOfnum2 = num2 & 1;
            num1 = num1 >> 1;
            num2 = num2 >> 1;

            int bitsum = lastbitOfnum1 ^ lastbitOfnum2 ^ carry;
            
            carry = (lastbitOfnum1 & lastbitOfnum2) |
                    (lastbitOfnum2 & carry) |
                    (lastbitOfnum1 & carry);

            ans = ans | (bitsum << i);
        }

        return ans;
    }
};