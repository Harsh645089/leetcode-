class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin() , nums.end());

        int triples_count = 0;

        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n ; j++){

                int low = j + 1;
                int high = n-1;

                int idx = j;

                while(low <= high){
                    int mid = low + (high - low)/2;

                    if(nums[mid] < nums[i] + nums[j]){
                        idx = mid;
                        low = mid + 1;
                    }

                    else{
                        high = mid -1;
                    }
                }

                triples_count += idx - j ; //this include the mid/idx one and exclude the jth one

            }
   
        }

        return triples_count;
    }
};