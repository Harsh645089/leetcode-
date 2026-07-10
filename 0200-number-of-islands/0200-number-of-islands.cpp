class Solution {
private:
    void dfs(int row , int col  , vector<vector<char>>& visit  , int m  , int n){
        visit[row][col] = '0' ;
        
        vector<int> drow = {-1 , 1 , 0 , 0};
        vector<int> dcol = {0 ,0 , -1 , 1};

        for(int i = 0  ; i < 4  ; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if( nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visit[nrow][ncol] == '1' ){
                dfs(nrow , ncol , visit , m , n);
            }
        }
    }

public:
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<char>> visit = grid ;
        int ans = 0 ;


        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(visit[i][j] == '1'){
                    ans++;
                    dfs( i  , j , visit  , m , n);
                }
            }
        }

        return ans;
    }
};