class Solution {
   public:
    // int solve(int m, int n, int i, int j, vector<vector<int>>& dp) {
    //     if (i == m - 1 && j == n - 1) {
    //         return 1;
    //     }
    //     if (i == m || j == n) {
    //         return 0;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // down
    //     int down = solve(m, n, i + 1, j, dp);

    //     // up
    //     int up = solve(m, n, i, j + 1, dp);

    //     return dp[i][j] = down + up;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(m, n, 0, 0, dp); }

        // base case
        for(int j=0;j<n;j++){
            dp[m-1][j] = 1;
        }

        for(int i=0;i<m;i++){
            dp[i][n-1] = 1;
        }
        // iteration
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                // down
                int down = dp[i + 1][j];

                // up
                int up = dp[i][j + 1];

                dp[i][j] = down + up;
            }
        }

        return dp[0][0];
    }
};