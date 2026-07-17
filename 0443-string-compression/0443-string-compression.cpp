class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
   
        char element = chars[0];
        vector<char> ans;
        ans.push_back(chars[0]);
        int count = 1;

        for(int i = 1; i < n ; i++){
            if(chars[i] != element){
                if(count > 1){
                    string cnt  = to_string(count);
                    for(char ch : cnt){
                        ans.push_back(ch);
                    }
                    
                }
                ans.push_back(chars[i]);
                element = chars[i];
                count = 1;
            }
            else{
                count++;
            }
        }

        if(count > 1){
            string cnt  = to_string(count);
            for(char ch : cnt){
                ans.push_back(ch);
            }
            
        }

        chars = ans;

        return ans.size();
    }
};