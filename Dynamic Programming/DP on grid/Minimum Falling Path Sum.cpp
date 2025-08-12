class Solution {
public:
    int solve(vector<vector<int>>& matrix, int m, int n, int i ,int j,vector<vector<int>>&dp){
        if(j < 0 || j >= n){
            return 1e9;
        }
        if(i == m ){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //choices
        //bottom left
        int bottomLeft = matrix[i][j] + solve(matrix, m, n, i+1, j-1, dp);

        //bottom straight
        int bottom = matrix[i][j] + solve(matrix, m, n, i+1,j, dp);

        //bottom right
        int bottomRight = matrix[i][j] + solve(matrix, m, n, i+1, j+1, dp);
        
        return dp[i][j] = min({bottomLeft, bottom, bottomRight});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            ans=min(ans,solve(matrix, m, n, 0, j, dp));
        }
        return ans;
    }
};