class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1;
        for(auto num : nums1){
            num1.insert(num);
        }

        unordered_set<int> common;
        for(auto num : nums2){
            if(num1.find(num) != num1.end()){
                //means it is common
                common.insert(num);
            }
        }
        unordered_set<int> zeroth;
        vector<int> ans1;
        for(auto num : nums1){
            if(common.find(num) == common.end()){
                zeroth.insert(num);
            }
        }

        for(auto num : zeroth){
            ans1.push_back(num);
        }
        

        unordered_set<int> first;
        vector<int> ans2;
        for(auto num : nums2){
            if(common.find(num) == common.end()){
                first.insert(num);
            }
        }

        for(auto num : first){
            ans2.push_back(num);
        }

        return {ans1, ans2};


    }
};