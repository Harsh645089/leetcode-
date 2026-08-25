class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        for(int num : nums){
            if(num % k == 0){
                st.insert(num);
            }
        }

        int multiple = k;

        while(st.find(multiple) != st.end()){
            multiple += k;
        }

        

        return multiple;
    }
};