class Solution {
   public:
    bool solve(vector<int> arr, int ind, int target,
               vector<vector<int>>& dp) {
        
        if(target == 0){
            return true;
        }
        if(ind == 0){
            if(arr[0] == target){
                return true;
            }
            return false;
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        bool notTake = solve(arr, ind -1, target, dp);

        bool take = false;
        if (target - arr[ind] >=0) {
            take = solve(arr, ind - 1, target - arr[ind], dp);
        }

        return dp[ind][target] = take || notTake;
    }
    bool equalPartition(int n, vector<int> arr) {
        // idea
        // find the total sum. if the half sum subarray exist in the
        // arr then true else false;
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(arr, n-1, target, dp);
    }
};
