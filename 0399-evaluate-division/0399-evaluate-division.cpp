class Solution {
public:
    double result(unordered_map<string  , vector<pair<string  , double>>> &adj , string source , string dest , unordered_set<string> &visited ){
        if(source == dest) return 1.0;

        visited.insert(source);

        for(auto node : adj[source]){
            string v = node.first;
            double val = node.second;
            if(visited.find(v) == visited.end()){
                double x = result(adj , v , dest  , visited);

                if(x != -1){
                    return x * val;
                }
                
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string  , vector<pair<string  , double>>> adj;

        int m = equations.size();

        for(int i = 0 ; i < m ; i++){
            string v1 = equations[i][0]; //first string
            string v2 = equations[i][1]; //second string

            adj[v1].push_back({v2 , values[i]});
            adj[v2].push_back({v1 , 1/double(values[i])});
        }

        //adj is completed

        int n = queries.size();
        vector<double> ans(n , 0.0);

        for(int i = 0 ; i < n ; i++){
            //i need to go from v1 to v2
            string v1 = queries[i][0]; //source
            string v2 = queries[i][1]; //destination

            if(adj.find(v1) == adj.end() || adj.find(v2) == adj.end()){
                //means variable not exist
                ans[i] = -1;
                continue;
            }

            //means they are present 
            unordered_set<string> visited;
            ans[i] = result(adj , v1 , v2 , visited);
        }

        return ans;
    }
};