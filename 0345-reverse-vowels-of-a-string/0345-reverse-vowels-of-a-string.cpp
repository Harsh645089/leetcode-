class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u';
    }
    string reverseVowels(string s) {
        int n = s.size();

        int i = 0 ;
        int j = n - 1;

        while (i <= j){
            if(isvowel(tolower(s[i])) && isvowel(tolower(s[j]))){
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            else if(isvowel(tolower(s[i]))){
                j--;
            }
            else{
                i++;
            }
        }

        return s;
        
    }
};