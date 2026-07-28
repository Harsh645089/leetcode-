class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int i = 0 ;
        int j = 0;
        int count = 0;
        while(i < n && j < n){
            if(isvowel(s[j])){
                count++;
            }

            if(j - i + 1 == k){
                ans = max(ans , count);
                if(isvowel(s[i])) count--;
                i++;
                j++;

            }

            else{
                j++;
            }
        }

        return ans;
    }
};