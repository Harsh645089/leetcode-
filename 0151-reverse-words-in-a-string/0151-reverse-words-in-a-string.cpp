class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        int n = s.size();
        string temp = "";

        for(int i = 0 ; i <  n ; i++){
            if(s[i] == ' '){
                if(!temp.empty()){
                    st.push(temp);
                    temp = "";
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }

        if(temp.size() != 0) st.push(temp);

        string ans = "";
        while(!st.empty()){
            string word = st.top();
            st.pop();
            ans += word;
            if(st.size() != 0)ans.push_back(' ');
        }

        return ans;
    }
};