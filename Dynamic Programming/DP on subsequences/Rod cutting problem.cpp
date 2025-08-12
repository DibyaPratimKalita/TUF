class Solution {
   public:
    int solve(vector<int>& price, int N, int ind, vector<vector<int>>&dp) {
        if (ind == price.size()) {
            return 0;
        }
        if(dp[ind][N] != -1){
            return dp[ind][N];
        }
        // not take
        int notTake = solve(price, N, ind + 1, dp);

        // take
        int take = 0;
        if (N - (ind + 1) >= 0) {
            take = price[ind] + solve(price, N - (ind + 1), ind, dp);
        }

        return dp[ind][N]=max(notTake, take);
    }
    int rodCutting(vector<int> price, int N) { 
        vector<vector<int>>dp(N, vector<int>(N+1,-1));
        return solve(price, N, 0, dp); 
        }
};
