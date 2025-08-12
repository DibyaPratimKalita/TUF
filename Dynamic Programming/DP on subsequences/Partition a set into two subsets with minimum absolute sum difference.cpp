class Solution {
   public:
    int solve(int currSum, int &mini, vector<int> &arr, int ind, int totalSum, vector<vector<int>>&dp) {
        if (ind == arr.size()) {
            return mini = min(mini, abs((totalSum - currSum) - currSum));
        }
        if(dp[ind][currSum] != -1){
            return dp[ind][currSum];
        }
        // not take
        int left = solve(currSum, mini, arr, ind + 1, totalSum, dp);
        // take
        int right = solve(currSum + arr[ind], mini, arr, ind + 1, totalSum, dp);

        return dp[ind][currSum] = min(left, right);
    }
    int minDifference(vector<int> &arr, int n) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        // generate all subsets;
        int currSum = 0;
        int mini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(totalSum,-1));
        return solve(currSum, mini, arr, 0, totalSum, dp);
    }
};
