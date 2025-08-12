class Solution{
	public:
    // int solve(vector<int>& coins, int amount, int ind, vector<vector<int>>&dp){
    //     if(ind == 0){
    //         if(amount % coins[ind] == 0){
    //             return amount / coins[ind];
    //         }
    //         return 1e9;
    //     }
    //     if(dp[ind][amount] != -1){
    //         return dp[ind][amount];
    //     }
    //     //not take
    //     int left = solve(coins, amount, ind-1, dp);

    //     //take 
    //     int right=INT_MAX;
    //     if(amount - coins[ind] >= 0){
    //          right = 1 + solve(coins, amount - coins[ind], ind, dp);
    //     }
           
    //     return dp[ind][amount]=min(left, right);
    // }
    int solve2(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        // Base case: for index 0 (first coin)
        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0){
                dp[0][amt] = amt / coins[0];
            }
            else dp[0][amt] = 1e9 ;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int left=dp[i-1][j];

                int right=INT_MAX;
                if(j - coins[i] >=0){
                    right=1 + dp[i][j-coins[i]];
                }

                dp[i][j]=min(left,right);
            }
        }

        int ans = dp[n-1][amount];
        return (ans == 1e9) ? -1 : ans;
    }
	int MinimumCoins(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= solve2(coins, amount);

        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};