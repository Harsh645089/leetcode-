class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mp;
        for(auto num : arr){
            mp[num]++;
        }

        unordered_set<int> st;
        for(auto p : mp){
            int occurance = p.second;
            if(st.find(occurance) == st.end()){
                st.insert(occurance);
            }
            else{
                return false;
            }
        }

        return true;
    }
};