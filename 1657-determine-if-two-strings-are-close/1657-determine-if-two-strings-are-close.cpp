class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        unordered_map<char , int> mp1;
        for(auto ch : word1){
            mp1[ch]++;
        }

        unordered_map<char , int> mp2;
        for(auto ch : word2){
            mp2[ch]++;
        }

        for(auto ch : word2){
            if(mp1.find(ch) == mp1.end()) return false;
        }

        for(auto ch : word1){
            if(mp2.find(ch) == mp2.end()) return false;
        }

        vector<int> v1;
        for(auto p : mp1){
            v1.push_back(p.second);
        }

        vector<int> v2;
        for(auto p : mp2){
            v2.push_back(p.second);
        }

        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());

        if(v1 != v2) return false;

        return true;
    }
};