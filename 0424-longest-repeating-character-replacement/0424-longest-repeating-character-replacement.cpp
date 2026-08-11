class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int ans = INT_MIN;
        vector<int> freq(26 ,0);
        int maxfreq = 0;
        
        for(int right = 0 ; right < n ; right ++ ){
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq , freq[s[right] - 'A'] );

            int windowlen = right - low + 1;

            //if the window is not valid then this will make it valid
            while(windowlen - maxfreq  > k){
                //means this window is not valid one
                freq[s[low] - 'A']--;
                low++;
                windowlen = right - low + 1;
                
            }
            
            ans = windowlen; //i have used the formula instead of windowlen as that may be not the valid one but if i used the formula then it only update the ans if it's size is more than the last valid one otherwise the invalid one will not able to update the ans as we are increasing the low for the invlaid window that decrease the window size then the last valid one , we can use while also but that increase the tc and this is also unnecesary as this can deal with the case with less tc 
        }
        return ans;
    }
};