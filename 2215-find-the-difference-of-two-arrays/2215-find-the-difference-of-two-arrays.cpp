class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1;
        for(auto num : nums1){
            set1.insert(num);
        }

        unordered_set<int> set2;
        for(auto num : nums2){
            set2.insert(num);
        }

        vector<int> ans1;
        vector<int> ans2;

        for(auto num : set1){
            if(set2.find(num) == set2.end()){
                //means not common
                ans1.push_back(num);
            }
        }

        for(auto num : set2){
            if(set1.find(num) == set2.end()){
                //not common
                ans2.push_back(num);
            }
        }
        
        return {ans1, ans2};


    }
};