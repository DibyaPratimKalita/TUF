class Solution {
   public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> currRow(i+1, 1);
            //note here dont write 
            //for (int k = 1; k <= currRow.size() - 2; k++)
            //bc currRow is size_t and it cannot be negative
            for (int k = 1; k < currRow.size() - 1; k++) {
                currRow[k] = ans[i - 1][k-1] + ans[i-1][k];
            }
            ans.push_back(currRow);
        }

        return ans;
    }
};