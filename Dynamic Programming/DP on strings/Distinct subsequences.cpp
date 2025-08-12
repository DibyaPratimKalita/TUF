class Solution {
    int mod=1e9+7;
    int solve(string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        if (j == t.size()) return 1;  // matched all of t
        if (i == s.size()) return 0;  // exhausted s

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // Both same, we have 2 options 
        //move both I and j, or move I only in search of other matching
        int moveBoth = 0, moveIOnly = 0;
        if (s[i] == t[j]) {
            moveBoth = solve(s, t, i + 1, j + 1, dp);
            moveIOnly = solve(s, t, i + 1, j, dp);

            return dp[i][j] = (moveBoth + moveIOnly) % mod;
        }
        //both not same, move only i
        int moveI = solve(s, t, i + 1, j, dp);
        
        return  dp[i][j] = (moveI) % mod;
    }

   public:
    int distinctSubsequences(string s, string t) { 
        int m=s.size(), n= t.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(s, t, 0, 0, dp) % mod; }
};
