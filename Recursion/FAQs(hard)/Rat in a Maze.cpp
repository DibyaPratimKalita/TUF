class Solution{
    public:
    void solve(vector<vector<int> > &grid,int i, int j,vector<string>&ans,string temp ){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        if(i==grid.size()-1 && j==grid.size()-1){
            ans.push_back(temp);
            return;
        }
        grid[i][j]=0;

        solve(grid,i+1,j,ans,temp+'D');
        solve(grid,i-1,j,ans,temp+'U');
        solve(grid,i,j-1,ans,temp+'L');
        solve(grid,i,j+1,ans,temp+'R');

        grid[i][j]=1;
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        if(grid[0][0]==0) return {};
        vector<string>ans;
        string temp;
        solve(grid,0,0,ans,temp);
        return ans;
    }
};