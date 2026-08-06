class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;

        while(i < n){
            if(s[i] != ']'){
                //means this is not the closing one so put it in the stack
                st.push(s[i]);
            }
            else{
                string temp;
                while(st.top() != '['){
                    temp.push_back(st.top());
                    st.pop();
                }

                reverse(temp.begin() , temp.end()); //as we have created in the reverse one

                st.pop(); //remove '[' 

                string number;
                while(!st.empty() && isdigit(st.top())){
                    number.push_back(st.top());
                    st.pop();
                }

                reverse(number.begin() , number.end());

                int num = stoi(number);

                for(int j = 0 ; j < num; j++){
                    for(auto ch : temp){
                        st.push(ch);
                    }
                }

            }

            i++;
        }


        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};