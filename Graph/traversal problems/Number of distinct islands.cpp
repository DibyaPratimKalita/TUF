class Solution {
   public:
    int m,n;

    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>>& visited, vector<pair<int,int>>&coordinatesVector, int iBase, int jBase){
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]==true || grid[i][j]==0){
            return;
        }
        visited[i][j]=true;
        coordinatesVector.push_back({i-iBase,j-jBase});
        
        dfs(i+1, j, grid, visited, coordinatesVector, iBase, jBase);
        dfs(i-1, j, grid, visited, coordinatesVector, iBase, jBase);
        dfs(i, j+1, grid, visited, coordinatesVector, iBase, jBase);
        dfs(i, j-1, grid, visited, coordinatesVector, iBase, jBase);
    }
    int countDistinctIslands(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,false));
        set<vector<pair<int,int>>>st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j]==false){
                    vector<pair<int,int>>coordinatesVector;
                    dfs(i, j, grid, visited, coordinatesVector, i, j);
                    st.insert(coordinatesVector);
                }
            }
        }

        return st.size();

    }
};
