class Solution {
public:

    static bool comp(pair<int , int> v1 , pair<int , int > v2){
        return v1.first > v2.first ;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int , int>> v;

        int n = nums1.size();

        for(int i = 0 ; i < n ;i++){
            v.push_back({nums2[i] , nums1[i]}); //i have kept the nums2 first because it will help me later
        }

        sort(v.begin() , v.end() , comp); //sorted in decreasing order

        priority_queue<int , vector<int> , greater<int>> pq;
        long long  sum = 0;
        
        for(int i = 0 ; i < k  ; i++){
            pq.push(v[i].second); //pushed top k elements and now the min of num2 is at k -1 idx after completion of for loop
            sum += v[i].second;
        }

        long long max_score = sum * v[k -1].first;

        for(int i = k ; i < n ; i++){
            pq.push(v[i].second);
            sum += v[i].second;
            if(pq.size() > k){
                sum -= pq.top(); //beacuse top one will got removed
                pq.pop();
            }

            max_score = max(max_score , sum * v[i].first);

        }


        return max_score;
    }
};