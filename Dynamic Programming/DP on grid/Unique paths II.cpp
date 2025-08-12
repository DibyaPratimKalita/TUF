class Solution {
   public:
    // int solve(vector<vector<int>>& matrix, int m, int n, int i, int j,
    //           vector<vector<int>>& dp) {
    //     if (i == m - 1 && j == n - 1) {
    //         return 1;
    //     }
    //     if (i == m || j == n || matrix[i][j] == 1) {
    //         return 0;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // down
    //     int down = solve(matrix, m, n, i + 1, j, dp);

    //     // up
    //     int up = solve(matrix, m, n, i, j + 1, dp);

    //     return dp[i][j] = down + up;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (matrix[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // return solve(matrix, m, n, 0, 0, dp);

        // base case
        dp[m - 1][n - 1] = 1;

        // iteration
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue; //base case

                if (matrix[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
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