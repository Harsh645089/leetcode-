class Solution {
public:
    string provideSnString(int n){
        if(n == 1){
            return "0";
        }

        string s_last  = provideSnString(n-1);


        string s_modified = s_last;

   
        for(auto &ch : s_modified){
            if(ch== '1') ch= '0';
            else ch= '1';
        }
        //got the inverted one

        reverse(s_modified.begin() , s_modified.end());

        return s_last + "1" + s_modified;
    }
    char findKthBit(int n, int k) {
        string Sn = provideSnString(n);
        return Sn[k-1];
    }
};