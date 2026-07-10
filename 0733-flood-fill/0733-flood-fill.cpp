class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int n , int m , int start_color){
        
        image[sr][sc] = color;

        int drow[] = {-1 , 1 , 0 , 0};
        int dcol[] = { 0 , 0 , -1 , 1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(ncol >= 0 && ncol < m  && nrow >=0 && nrow < n && image[nrow][ncol] == start_color){
                dfs(image , nrow , ncol , color , n, m , start_color);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int start_color = image[sr][sc] ;
        if(color == start_color) return image;
        dfs(image , sr , sc , color , n, m , start_color);
        return image ;
    }
};