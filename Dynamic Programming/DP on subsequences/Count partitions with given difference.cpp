#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int mod = 1e9 + 7;
    int solve(int currSum, vector<int>& arr, int K, int ind,
              vector<vector<int>>& dp) {
        if (ind == arr.size()) {
            if (currSum == K) {
                return 1;
            } else
                return 0;
        }
        // if currSum exceeds K(max size of dp table) then we have invalid
        // access
        if (dp[ind][currSum] != -1) {
            return dp[ind][currSum];
        }
        // not take
        int leftCount = solve(currSum, arr, K, ind + 1, dp);

        // take
        int rightCount = 0;
        // we are making this check just because dp table is set to max size
        // till K, if currSum exceeds K, we cannot store the value, look
        //  above case
        if (currSum + arr[ind] <= K) {
            rightCount = solve(currSum + arr[ind], arr, K, ind + 1, dp);
        }

        return dp[ind][currSum] = (leftCount + rightCount) % mod;
    }
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if((totalSum + diff) % 2 != 0) return 0;
        
        int K = (totalSum + diff) / 2;
        // rest is just find count of target like previos question
        int currSum = 0;
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        return solve(currSum, arr, K, 0, dp) % mod;
    }
};