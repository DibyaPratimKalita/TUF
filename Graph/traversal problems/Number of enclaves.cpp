class Solution{
public:
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()
        || grid[i][j]==0){
            return;
        }

        grid[i][j]=0;

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);

    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size();
        for(int col=0;col<n;col++){
            dfs(col,0,grid);
        }
        for(int col=0;col<n;col++){
            dfs(col,m-1,grid);
        }
        for(int row=1;row<=m-2;row++){
            dfs(0,row,grid);
        }
        for(int row=1;row<=m-2;row++){
            dfs(n-1,row,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }

        return ans;
    }
};
