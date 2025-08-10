class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                int start = i + 1, end = n - 1;

                while (start < end) {
                    long long sum = (long long)nums[start] + nums[end] + nums[i] + nums[j];
                    if (sum == target) {
                        vector<int> quad = {nums[j], nums[i], nums[start], nums[end]};
                        sort(quad.begin(), quad.end()); // ✅ Ensure correct order before inserting
                        ans.insert(quad);
                        start++;
                        end--;
                    } else if (sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());  // Convert set to vector
    }
};