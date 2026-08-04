class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto ch : s){
            if(ch == '*'){
                if(ans.empty() == false) ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};