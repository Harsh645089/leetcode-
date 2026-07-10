class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();

        vector<vector<int>> visit(m , vector<int>(n , 0));
        queue<pair<int, int>> q;

        for(int j = 0 ; j < n ; j++){
            if(grid[0][j] == 1){
                q.push({0 , j});
                visit[0][j] = 1;
            }
        }

        for(int j = 0 ; j < n ; j++){
            if(grid[m-1][j] == 1){
                q.push({m-1 , j});
                visit[m-1][j] = 1;
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(grid[i][0] == 1){
                q.push({i , 0});
                visit[i][0] = 1;
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(grid[i][n -1] == 1){
                q.push({i , n -1});
                visit[i][n -1] = 1;
            }
        }

        vector<int> delrow = { -1 , 1, 0 , 0};
        vector<int> delcol = { 0 , 0 , -1 , 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visit[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    visit[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visit[i][j] == 0 && grid[i][j] == 1 ){
                   count++;
                }
            }
        }

        return count ;
    }

};