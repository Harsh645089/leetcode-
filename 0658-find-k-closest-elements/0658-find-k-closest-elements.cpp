class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue< pair<int  , int>, vector<pair<int  , int>> , greater<pair<int  , int>>> pq;

        for(auto num : arr){
            pq.push({abs(num - x) , num});
        }

        vector<int> ans;

        while(k > 0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;

        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};