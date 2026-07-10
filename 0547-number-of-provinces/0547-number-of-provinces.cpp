class Solution {
private:
    void bfs(int node , vector<int> &visit ,  vector<vector<int>>& isConnected , int n ){
        queue<int> q;
        q.push(node);
        visit[node] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int i = 0 ; i < n ; i++ ){
                if(isConnected[u][i] == 1 && !visit[i]){
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        int ans = 0 ; 
        vector<int> visit(n , 0);
        for(int i = 0 ; i < n ; i++){
            if(!visit[i] ){
                ans++;
                bfs(i , visit , isConnected  , n);

            }
        }
        
        return ans;
    }
};