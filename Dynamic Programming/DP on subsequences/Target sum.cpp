class Solution {
   public:
    int mod = 1e9+7;
    int totalSumOffset;
    int solve(int target, vector<int>& nums, int currSum, int ind,
              vector<vector<int>>& dp) {
        if (ind == nums.size()) {
            if (currSum == target) {
                return 1;
            }
            return 0;
        }
        int normalizedSum = currSum + totalSumOffset;
        if (dp[ind][normalizedSum] != -1) {
            return dp[ind][normalizedSum];
        }

        // take -
        int left = solve(target, nums, currSum - nums[ind], ind + 1, dp);

        // take +
        int right = solve(target, nums, currSum + nums[ind], ind + 1, dp);

        return dp[ind][normalizedSum] = (left + right) % mod;
    }
    int targetSum(int n, int target, vector<int>& nums) {
        int currSum = 0;
        // saving states of index and currSum;
        // note that here the sum can go negative which cannot be
        // stored in dp table directly, therefore we normalize it
        // by using offset here ie the totalsum [-x,0] to [0,x];
        totalSumOffset = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(2 * totalSumOffset + 1, -1));
        return solve(target, nums, currSum, 0, dp) % mod;
    }
};
