class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st1;
        unordered_set<int> st2;

        for(auto num : nums1){
            st1.insert(num);
        }

        for(auto num : nums2){
            st2.insert(num);
        }

        vector<int> ans;

        for(auto num : st1){
            if(st2.find(num) != st2.end()){
                ans.push_back(num);
            }
        }

        return ans;
    }
};