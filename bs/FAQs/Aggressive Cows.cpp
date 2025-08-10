class Solution {
   public:
    bool isValid(int i, vector<int> &nums, int k) {
        int count = 1;
        int lastpos = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] - nums[lastpos] >= i) {
                count++;
                lastpos = j;
            }
            if (count == k) {
                return true;
            }
        }

        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        // search range is 1 to max(nums)
        sort(nums.begin(), nums.end());
        int end = nums[nums.size() - 1];
        int start = 1;
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(mid, nums, k) == true) {
                ans = mid;
                start=mid+1;
            } else {
                end= mid - 1;
            }
        }
        return ans;
    }
};