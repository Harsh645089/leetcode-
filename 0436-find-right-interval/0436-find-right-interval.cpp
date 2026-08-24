class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n );

        vector<pair<vector<int> , int>> arr; //i can optimised it by storing the start of the interval as it is the one that i need 

        for(int i = 0 ; i < n ; i++){
            arr.push_back({intervals[i] , i});
        }

        sort(arr.begin() , arr.end());

        for(int i = 0 ; i < n ; i++){
            int start_ = arr[i].first[0];
            int end = arr[i].first[1];
            int end_idx = arr[i].second; //this is the idx of the end
            int ans = -1;
            int low = i + 1;
            int high = n -1;

            if(start_ == end){
                ans = end_idx;
                result[end_idx] = ans;
                continue;
            }

            while(low <= high){
                int mid = low + (high - low)/2;

                int start = arr[mid].first[0];
                int start_idx = arr[mid].second;

                if(start >= end){
                    ans = start_idx;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            result[end_idx] = ans;

        }

        return result;
    }
};