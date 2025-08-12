/*


"a a b"

*/

class Solution {
   public:
    bool isPali(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    int solve(string s, int i, int j, vector<vector<int>>&dp) {
        if (i >= j) {
            return 0;
        }

        if (isPali(s.substr(i, j-i+1)) == true) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;

        for (int k = i; k <= j; k++) {
            string str = s.substr(i, k - i + 1);
            if (isPali(str) == true) {
                ans = min(ans, 1 + solve(s, k + 1, j, dp));
            }
        }

        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};