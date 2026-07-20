class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0 ; i < 32 ; i++){
            if(((1 << i) & c) != 0){
                //means is active 
                if(((1 << i) & a) == 0 && ((1 << i) & b) == 0){
                    count++;
                }
            }
            else{
                //means that bit is not active
                if(((1 << i) & a) != 0){
                    //means a is active
                    count++;
                }
                if(((1 << i) & b) != 0){
                    //b is also active
                    count++;
                }
            }
        }

        return count;
    }
};