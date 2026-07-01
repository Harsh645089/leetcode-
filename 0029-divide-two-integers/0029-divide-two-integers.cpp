class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = false;//means no need to change the sign
        if(dividend >= 0 && divisor < 0) sign = true;
        if(dividend < 0 && divisor > 0) sign = true;

        long long  n = abs((long long)dividend);
        long long m = abs((long long)divisor);
        long long count = 0;

        for(int i = 31 ; i >= 0 ; i--){
            if((m << i) <= n){
                //3 * n means taking n 3's and adding it and the maximum that we can add to male the sum closest to n so we have to add n in count as we are first taking the bigger number that are multliples of 3 and it the max that we can remove from n  so adding the multiple factor to the count as explained above
                count +=  (1LL << i);

                n -= (m << i);
            }
        }

        if(sign){
            return -count;
        }

        return count; 
    }
};