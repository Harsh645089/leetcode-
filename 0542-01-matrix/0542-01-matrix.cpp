class Solution {
public:

    //this is the one more application of multi bfs  , similar to rotten organes

    void solve(int m  , int n , vector<vector<int>> &ans , vector<vector<int>> &visit , vector<vector<int>> &mat){

        queue<pair<int , int >> q;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    q.push({i , j} );
                    visit[i][j] = 1;
                }
            }
        }

        //till now all the 0s are maked as visited so now in future if i got anything that is not visited then it is a 1 only

        int dis = 0;

        while(!q.empty()){

            int q_size = q.size();
            bool added = false;

            for(int i = 0 ; i < q_size; i++){
                int row = q.front().first;
                int col = q.front().second;
                

                ans[row][col] = dis;

                q.pop();

                int drow[] = {-1 , 1, 0 , 0};
                int dcol[] = { 0 ,0  , -1 , 1};

                for(int i = 0 ; i < 4 ; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visit[nrow][ncol] == 0 ){
                        visit[nrow][ncol] = 1;
                        q.push({nrow , ncol});
                        added = true;
                    }
                }
            }

            

            if(added) dis++;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m  = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m , vector<int>(n));
        vector<vector<int>> visit(m , vector<int>(n , 0));

        solve(m , n ,ans , visit , mat);

        return ans;
    }
};