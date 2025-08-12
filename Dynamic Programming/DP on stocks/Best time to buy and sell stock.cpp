class Solution {
   public:
    int stockBuySell(vector<int> arr, int n) {
        int profit = 0;
        int buyPrice = arr[0];
        for (int i = 0; i < n; i++) {
            buyPrice = min(buyPrice, arr[i]);
            profit = max(profit, arr[i] - buyPrice);
        }

        return profit;
    }
};
