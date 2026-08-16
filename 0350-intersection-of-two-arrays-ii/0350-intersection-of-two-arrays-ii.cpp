class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        vector<int> ans ;

        
        for(auto num : nums1){
            int n = nums2.size();
            int low = 0;
            int high = n -1;

            while(low <= high && nums2.size() > 0){
                int mid = low + (high - low)/2;

                if(nums2[mid] == num){
                    ans.push_back(num);
                    nums2.erase(nums2.begin() + mid);
                    break;

                }

                else if(nums2[mid] < num){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};