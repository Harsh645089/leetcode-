class Solution {
private:
    bool bfs(vector<vector<int>>& graph , vector<int> &color , int node , int col){
        color[node] = col ;
        queue<int> q;

        q.push(node);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v : graph[u]){
                if(color[v] == -1){
                    color[v] = !color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    return false;
                }
            }
        }

        return true ;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        

        vector<int> color(n , -1);

        for(int i = 0 ; i  < n ;i++){
            if(color[i] == -1){
                if(bfs(graph , color , i  , 0 ) == false){
                    return false;
                }
            }
        }
        

        return true;
    }
};