class Solution {
private:
    void bfs(vector<vector<int>>& grid , vector<vector<int>>& visit ,int &time , int n , int m , queue<pair<int , int>> q){


        


        while(!q.empty()){

            int q_size = q.size();
            bool continue_ = false;  

            for(int i = 0 ; i < q_size  ; i++){

                auto node = q.front();
                int orow = node.first;
                int ocol = node.second;
                
                q.pop();

                int drow[] = {-1 , 1, 0 , 0};
                int dcol[] = {0  , 0 , -1 , 1};

                for(int i = 0 ; i < 4  ; i++){

                    int nrow = orow + drow[i];
                    int ncol = ocol + dcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visit[nrow][ncol] && grid[nrow][ncol] == 1){
                        visit[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow , ncol});
                        continue_ = true;
                        //means only update the time when add element in the queue and there is one or more iterations remain 
                    }
                }

            }

            if(continue_) time++; 
        }
    }

public:

    

    int orangesRotting(vector<vector<int>>& grid) {

        

        int n= grid.size();
        int m = grid[0].size();

        vector<vector<int>> visit(n , vector<int>(m , 0));

        int time = 0 ;

        queue<pair<int , int>> q;

        for(int i = 0 ; i < n ; i++){
            for(int j  = 0 ; j < m ; j++){
                if(grid[i][j] == 2 && !visit[i][j]){
                    visit[i][j] = 1;
                    q.push({i , j});
                }
            }
        }

        bfs(grid , visit , time , n  , m , q);

        for(int i = 0 ; i < n ; i++){
            for(int j  = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        

        return time ;
        
    }
};