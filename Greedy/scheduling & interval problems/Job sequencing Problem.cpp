class Solution {
   public:
    bool static comparator(vector<int>& a, vector<int>& b) {
        if (a[2] > b[2]) {
            return true;
        }
        return false;
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        // greedily sort based on the profit
        sort(Jobs.begin(), Jobs.end(), comparator);

        int n = Jobs.size();

        int maxDeadline = -1;
        for (auto it : Jobs) {
            maxDeadline = max(maxDeadline, it[1]);
        }
        vector<int> hash(maxDeadline + 1, -1);

        int cnt = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            /* Iterate over each deadline slot
            starting from the job's deadline */
            for (int j = Jobs[i][1] - 1; j >= 0; j--) {
                // If the current deadline slot is available
                if (hash[j] == -1) {
                    cnt++;                      // Count of selected jobs
                    hash[j] = Jobs[i][0];       // Mark the job as selected
                    totalProfit += Jobs[i][2];  // Update the total profit

                    // Move to the next job
                    break;
                }
            }
        }
        return {cnt, totalProfit};
    }
    };