class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ans;
        int low  = 0;
        int high = 9;
        int n = s.size();
        unordered_map<string , int> mp;
 
        
        while(high < n){
            string target = s.substr(low  , 10);

            if(mp.find(target) == mp.end()){
                //first time putting it

                mp[target] = 0;

            }
            else if(mp[target] == 0){
                //2nd time 
                
                ans.push_back(target);
                mp[target] = 1;
            }

            low++;
            high++;
        }

        return ans;


    }
};