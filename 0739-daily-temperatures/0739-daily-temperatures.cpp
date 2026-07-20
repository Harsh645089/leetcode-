class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n , 0);
        for(int i = n -1 ; i >= 0 ; i--){
            if(st.empty()){
                //no element in the stack mean there is no one that warmer thann this 
                ans[i] = 0;
                st.push(i);
            }
            else{
                //there are elements in the stack 
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop(); // remving the invariant elements
                }

                if(!st.empty()){
                    ans[i] = st.top() - i; // as now the top element is the first warmer element 
                    st.push(i); //as this is smaller than the top so this can be a ans for some temp
                }
                else{
                    ans[i] = 0;
                    st.push(i);
                }
            }
        }

        return ans;
    }
};