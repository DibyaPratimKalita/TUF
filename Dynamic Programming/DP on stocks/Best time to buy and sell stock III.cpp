class Solution{
public:
    int solve(vector<int>& arr, int i, bool didBuy, vector<vector<vector<int>>>&dp, int cap){
        //base case
        if(cap == 0) {
            return 0;
        }
        if(i == arr.size()){
            return 0;
        }
        if(dp[i][didBuy][cap] != -1){
            return dp[i][didBuy][cap];
        }
        //if did not buy , can buy now or not buy now
        if(didBuy == false){
            int buy = -arr[i] + solve(arr, i+1, true, dp, cap);
            int notBuy = solve(arr, i+1, false, dp, cap);

            return dp[i][didBuy][cap] = max(buy, notBuy);
        }
        // //if did buy , can sell now or not sell now
        // note that 1 transaction is completed only when we sell it, so then
        //cap -1;
        else{
            int sell =  arr[i] + solve(arr, i+1, false, dp, cap - 1);
            int notSell = solve(arr, i+1, true, dp, cap);

            return dp[i][didBuy][cap] = max(sell, notSell);
        }

        return 0;
        
    }
    int stockBuySell(vector<int> arr, int n){
        int didBuy = false;
        int cap = 2;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(cap+1,-1)));
        return solve(arr, 0, didBuy, dp, cap);
    }
};

