class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0 ; i < 32 ; i++){
            int abit = (1 << i) & a ;
            int bbit = (1 << i) & b ;
            int cbit = (1 << i) & c ;

            if(cbit != 0){
                //means is active 
                if(abit == 0 && bbit == 0){
                    count++;
                }
            }
            else{
                //means that bit is not active
                if(abit!= 0){
                    //means a is active
                    count++;
                }
                if(bbit != 0){
                    //b is also active
                    count++;
                }
            }
        }

        return count;
    }
};