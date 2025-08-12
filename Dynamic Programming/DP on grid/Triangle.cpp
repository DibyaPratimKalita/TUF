class Solution {
   public:
    int solve(vector<vector<int>>& matrix, int m, int n, int i, int j,
              vector<vector<int>>& dp) {
        if (j < 0 || j >= n) {
            return 1e9;
        }
        if (i == m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // choices

        // bottom straight
        int bottom = matrix[i][j] + solve(matrix, m, n, i + 1, j, dp);

        // bottom right
        int bottomRight = matrix[i][j] + solve(matrix, m, n, i + 1, j + 1, dp);

        return dp[i][j] = min({bottom, bottomRight});
    }
    int minTriangleSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        ans = min(ans, solve(matrix, m, n, 0, 0, dp));

        return ans;
    }
};
