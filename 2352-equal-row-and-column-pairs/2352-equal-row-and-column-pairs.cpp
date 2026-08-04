class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int> , int> mp;
        for(int i = 0 ; i < n ; i++){
            //i represent the element of the grid[j] we are taking
            vector<int> col;
            for(int j = 0 ; j < n ; j++){
                col.push_back(grid[j][i]);
            }

            mp[col]++;
        }

        int count = 0;

        for(auto row : grid){
            if(mp.find(row) != mp.end()){
                //means i got the one that is same
                count += mp[row];
            }
        }

        return count;
    }
};