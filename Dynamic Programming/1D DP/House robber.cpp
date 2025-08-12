// indexing from the back
//tabulation
class Solution {
   public:

    int solve1(vector<int>& money, int lowerlimit, int upperlimit) {
        int size = upperlimit - lowerlimit + 1;
        if (size == 1) return money[lowerlimit];

        vector<int> dp(size, 0);
        dp[0] = money[lowerlimit];
        dp[1] = max(money[lowerlimit], money[lowerlimit + 1]);

        for (int i = 2; i < size; i++) {
            int skip = dp[i - 1];
            int steal = money[lowerlimit + i] + dp[i - 2];
            dp[i] = max(skip, steal);
        }

        return dp[size - 1];
    }
    int houseRobber(vector<int>& money) {
        int n = money.size();
        
        if (n == 1) return money[0];
        // for index 0 to n-2
        int take0 = solve1(money, 0, n - 2);

        // for index 1 to n-1
        int take1 = solve1(money, 1, n - 1);

        return max(take0, take1);
    }
};
