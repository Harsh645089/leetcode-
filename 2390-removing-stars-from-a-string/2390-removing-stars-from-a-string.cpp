class Solution {
public:
    string removeStars(string s) {
        int top = 0;

        for(auto ch : s){
            if(ch == '*'){
                top--;
            }
            else{
                s[top] = ch;
                top++;
            }
        }

        s.resize(top);
        return s;
    }
};