class Solution {
public:
    int reverseBits(int number) {
        int n = number;
        int ans = 0;
        for(int i = 31  ; i >= 0 ; i--){
            int lastbit = n & 1; //got the last bit
            n = n >> 1; //removed that last bit

            lastbit = lastbit << i;
            //to set the last position 
    

            ans = ans | lastbit;
        
        }

        return ans;

    }
};