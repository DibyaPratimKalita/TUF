class Solution{
    // int solve(string &str1, string &str2, int i, int j,
    //           vector<vector<int>> &dp) {
    //     if (i == str1.size() || j == str2.size()) {
    //         return 0;
    //     }

    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // both have same
    //     int bothSame = 0;
    //     if (str1[i] == str2[j]) {
    //         bothSame = 1 + solve(str1, str2, i + 1, j + 1, dp);
    //     }

    //     // both not same

    //     // i move forward
    //     int iMove = solve(str1, str2, i + 1, j, dp);

    //     // j move forward
    //     int jMove = solve(str1, str2, i, j + 1, dp);

    //     return dp[i][j] = max(bothSame, max(iMove, jMove));
    // }
  public: int longestPalinSubseq(string str1) {
        string str2= str1;
        reverse(str2.begin(),str2.end());
        
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // return solve(str1, str2, 0, 0, dp);

        // base case
        //handled by the dp initialization
       
        // iteration
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // both have same
                int bothSame = 0;
                if (str1[i] == str2[j]) {
                    bothSame = 1 + dp[i + 1][j+1]; 
                }

                // both not same

                // i move forward
                int iMove = dp[i + 1][j];

                // j move forward
                int jMove = dp[i][j + 1];

                dp[i][j] = max(bothSame, max(iMove, jMove));
            }
        }

        return dp[0][0];
    }
};
