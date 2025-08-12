class Solution {
  public:
  int mod=1e9+7;
   int solve(vector<int>& coins, int amount, int ind, vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[ind] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        //not take
        int left = solve(coins, amount, ind-1, dp);

        //take 
        int right=0;
        if(amount - coins[ind] >= 0){
             right = solve(coins, amount - coins[ind], ind, dp);
        }
           
        return dp[ind][amount]=(left + right) % mod;
    }
   int count(vector<int>&coins, int N, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins, amount, n-1, dp);

        return ans % mod;
    }
};
