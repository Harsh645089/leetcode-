class Solution {
public:
    int maxConsecutiveAnswers(string answerkey, int k) {
        int n = answerkey.size();
        int low = 0;
        int ans = INT_MIN;
        int maxfreq = 0;
        unordered_map<int , int> mp;

        for(int high = 0 ; high < n ; high++){
            mp[answerkey[high]]++;

            maxfreq = max(maxfreq , mp[answerkey[high]]);

            int len = high - low + 1;

            if(len - maxfreq > k){
                //means this window is invalid
                mp[answerkey[low]]--;
                low++;
            }

            ans = max(ans , high - low + 1);
        }

        return ans;
    }
};