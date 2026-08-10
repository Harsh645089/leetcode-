class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ans;
        int low  = 0;
        int high = 9;
        int n = s.size();
        unordered_set<string> st;
        unordered_set<string> ansset;
        
        while(high < n){
            string target = s.substr(low  , 10);

            if(st.find(target) != st.end()){
                ansset.insert(target);

            }
            else{
                st.insert(target);
            }

            low++;
            high++;
        }

        for(auto str : ansset){
            ans.push_back(str);
        }

        return ans;


    }
};