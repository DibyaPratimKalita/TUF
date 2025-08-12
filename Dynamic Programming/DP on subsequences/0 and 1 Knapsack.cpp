// trying indexing from backside, see other submissions for front side
class Solution {
   public:
    // int solve(vector<int>& wt, vector<int>& val, int W, int ind,
    //           vector<vector<int>>& dp) {
    //     if (ind == 0) {
    //         if (wt[0] <= W) {
    //             return val[0];
    //         }
    //         return 0;
    //     }
    //     if (dp[ind][W] != -1) {
    //         return dp[ind][W];
    //     }
    //     // not take
    //     int left = solve(wt, val, W, ind - 1, dp);

    //     // take
    //     int right = 0;
    //     if (W - wt[ind] >= 0) {
    //         right = val[ind] + solve(wt, val, W - wt[ind], ind - 1, dp);
    //     }

    //     return dp[ind][W] = max(left, right);
    // }
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        
        // Base case: Fill first row (item 0)
        for (int j = 0; j <= W; j++) {
            if (wt[0] <= j) {
                dp[0][j] = val[0];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= n-1; i++) {
            for (int j = 0; j <= W; j++) {
                // Not take current item
                int notTake = dp[i - 1][j];
                
                // Take current item (if possible)
                int take = 0;
                if (j >= wt[i]) {
                    take = val[i] + dp[i - 1][j - wt[i]];
                }
                
                dp[i][j] = max(notTake, take);
            }
        }
        
        return dp[n - 1][W];
    }
};