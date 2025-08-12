class Solution{
public:
    int solve(vector<int>& arr, int i, bool didBuy, vector<vector<int>>&dp){
        //base case
        if(i == arr.size()){
            return 0;
        }
        if(dp[i][didBuy] != -1){
            return dp[i][didBuy];
        }
        //if did not buy , can buy now or not buy now
        if(didBuy == false){
            int buy = -arr[i] + solve(arr, i+1, true, dp);
            int notBuy = solve(arr, i+1, false, dp);

            return dp[i][didBuy] = max(buy, notBuy);
        }
        // //if did buy , can sell now or not sell now
        else{
            int sell =  arr[i] + solve(arr, i+1, false, dp);
            int notSell = solve(arr, i+1, true, dp);

            return dp[i][didBuy] = max(sell, notSell);
        }

        return 0;
        
    }
    int stockBuySell(vector<int> arr, int n){
        int didBuy = false;
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(arr, 0, didBuy, dp);
    }
};

