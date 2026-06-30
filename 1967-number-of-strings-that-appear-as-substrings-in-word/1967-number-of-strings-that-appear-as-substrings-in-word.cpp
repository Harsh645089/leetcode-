class Solution {
public:
    bool check(string pattern , string word){
        int n = word.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                string substring = word.substr(i , j - i + 1);
                if(substring == pattern){
                    return true;
                }
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto pattern : patterns){
            if(check(pattern , word )){
                count++;
            }
        }
        return count;
    }
};