class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        int total = 0;
        for(int i = 1 ; i <= n ; i++){
            total = total ^ i;
        }

        int odd_idx_xor = 0;
        //this is the xor of the odd idx of the encoded that make this 
        // p1 ^ p2 ... ^ pn-1 ;
        for(int i = 1 ; i < n -1 ; i = i + 2){
            odd_idx_xor ^= encoded[i] ;
        }

        vector<int> perm(n);

        perm[0] = (total ^ odd_idx_xor) ;

        for(int i = 1 ; i < n ; i++){
            perm[i] = encoded[i-1] ^ perm[i-1];
        }

        return perm;


    }
};