class Solution {
   public:
    int findKRotation(vector<int> &nums) {
        int start = 0, end = nums.size() - 1;
        int index = -1;
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[start] <= nums[mid]) {
                if (nums[start] < ans) {
                    index = start;
                    ans = nums[start];
                }
                start = mid + 1;

            } else {
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                end = mid - 1;
            }
        }
        return index;
    }
};