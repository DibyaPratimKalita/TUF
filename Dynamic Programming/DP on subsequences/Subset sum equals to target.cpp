class Solution {
   public:
    bool solve(vector<int> arr, int ind, int sum, int target, vector<vector<int>>&dp) {
        if (ind == arr.size()) {
            if (sum == target) {
                return true;
            }
            return false;
        }
        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        bool notTake = solve(arr, ind + 1, sum,target, dp);

        bool take=false;
        if(sum + arr[ind] <= target ){
            take = solve(arr, ind + 1, sum + arr[ind], target, dp);
        }
        
        return dp[ind][sum]=take || notTake;
    }
    bool isSubsetSum(vector<int> arr, int target) {
        // generate all the subset
        int n = arr.size();
        int sum = 0;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(arr, 0, sum, target, dp);
       
    }
};