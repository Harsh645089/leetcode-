class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n = spells.size();
        int m = potions.size();

        sort(potions.begin() , potions.end());

        vector<int> ans(n);

        for(int i = 0 ; i < n ; i++){
            int spell = spells[i];
            int low = 0;
            int high = m -1;
            int position = m;

            while(low <= high){
                int mid = low + (high-low)/2;

                if((long long )potions[mid] * spell >= success){
                    position = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            ans[i] = m - position ;
        }

        return ans;
        
    }
};