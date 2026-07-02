class Solution {
public:

    char invert(char i){
        if(i == '1') return '0';
        return '1';
    }

    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = (1<< n) -1;
        int mid = len/2 + 1; //as the len is always odd

        if(mid == k){
            //means is the mid of the both string and that is 1
            return '1';
        }
        else if(k < mid){
            //means it is in the sn-1 string so find in that only 
            return findKthBit(n-1 , k);
        }
        else{
            //the k is in the inverted and reversed string of n-1
            /*
                      k
                ------|
                ***********
                       ----
                        (n-k) but the kth is one more so (n - k + 1) to get the kth position


            */

            int newk = len - k + 1;
            return invert(findKthBit(n-1 , newk));
        }
    }
};