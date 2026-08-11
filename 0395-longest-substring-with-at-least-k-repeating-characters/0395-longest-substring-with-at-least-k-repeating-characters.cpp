class Solution {
public:
    int solve(int low , int high , string &s , int k ){
        unordered_map<char , int> mp;
    
        for(int i = low ; i <= high ; i++){
            mp[s[i]]++;
        }

        for(int i = low ; i <= high ; i++){
            if(mp[s[i]] < k){
                //this ith char's freq is less than k means this cannot be the part of any substring
                int left = solve(low , i -1 ,s ,k);
                int right = solve(i+1 , high , s , k);

                return max(left , right);
            }
        }

        return high - low + 1; //means there is not issue in this windown return it's length
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        return solve(0 , n -1, s , k);
    }
};