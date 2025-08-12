class Solution {
   public:
    int mod = 1e9 + 7;
    // int solve(int currSum, vector<int>& arr, int K, int ind,
    //           vector<vector<int>>& dp) {
    //     if (ind == arr.size()) {
    //         if (currSum == K) {
    //             return 1;
    //         } else
    //             return 0;
    //     }
    //     // if currSum exceeds K(max size of dp table) then we have invalid
    //     // access
    //     if (dp[ind][currSum] != -1) {
    //         return dp[ind][currSum];
    //     }
    //     // not take
    //     int leftCount = solve(currSum, arr, K, ind + 1, dp);

    //     // take
    //     int rightCount = 0;
    //     // we are making this check just because dp table is set to max size
    //     // till K, if currSum exceeds K, we cannot store the value, look
    //     //  above case
    //     if (currSum + arr[ind] <= K) {
    //         rightCount = solve(currSum + arr[ind], arr, K, ind + 1, dp);
    //     }

    //     return dp[ind][currSum] = (leftCount + rightCount) % mod;
    // }
    int perfectSum(vector<int>& arr, int K) {
        int n=arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
        // return solve(currSum, arr, K, 0, dp) % mod;

        // base case
        for (int currSum = 0; currSum <= K; currSum++) {
            if (currSum == K) {
                dp[n][currSum] = 1;
            } else {
                dp[n][currSum] = 0;
            }
        }
        // iteration
        for (int i = n - 1; i >= 0; i--) {
            for (int j = K; j >= 0; j--) {
                // not take
                int leftCount = dp[i + 1][j];

                // take
                int rightCount = 0;
                if (j + arr[i] <= K) {
                    rightCount = dp[i + 1][j + arr[i]];
                }

                dp[i][j] = (leftCount + rightCount) % mod;
            }
        }

        return dp[0][0];
    }
};