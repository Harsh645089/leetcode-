class Solution {
public:
    int equalPairs(vector<vector<int>>& rows) {
        int n = rows.size();

        vector<vector<int>> cols;
        for(int i = 0 ; i < n ; i++){
            //i represent the element of the grid[j] we are taking
            vector<int> col;
            for(int j = 0 ; j < n ; j++){
                col.push_back(rows[j][i]);
            }

            cols.push_back(col);
        }

        int count = 0;

        for(auto row : rows){
            for(auto col : cols){
                if(row == col) count++;
            }
        }

        return count;
    }
};