class Solution {
   public:
    int solve(vector<int>& wt, vector<int>& val, int W, int ind, vector<vector<int>>&dp){
        if(ind == wt.size()){
            return 0;
        }

        if(dp[ind][W] != -1){
            return dp[ind][W];
        }
        //not take
        int notTake = solve(wt, val, W, ind+1, dp);

        //take
        int take=0;
        if(W - wt[ind] >= 0){
             take = val[ind] + solve(wt, val, W - wt[ind], ind, dp);
        }

        return dp[ind][W]=max(notTake, take);
        
    }
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(wt, val, W, 0, dp);
    }
};
