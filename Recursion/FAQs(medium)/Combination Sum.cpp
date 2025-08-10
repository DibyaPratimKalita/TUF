class Solution {
   public:
    void solve(vector<vector<int>>& ans, int target, vector<int>& temp, int sum,
               int i, vector<int>& candidates) {
        if (i == candidates.size()) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        if (sum > target ||
            i ==candidates.size()) {  // Base case: sum exceeded or no more candidates
            return;
        }

        // pick
        sum += candidates[i];
        temp.push_back(candidates[i]);
        solve(ans, target, temp, sum, i, candidates);
        sum -= candidates[i];
        temp.pop_back();

        // not pick
        solve(ans, target, temp, sum, i + 1, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, target, temp, 0, 0, candidates);
        return ans;
    }
};