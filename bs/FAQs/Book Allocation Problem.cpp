class Solution {
   public:
    bool isValid(vector<int> &nums, int m,int i) {
        int student = 1;
        int pages = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (pages + nums[j] <= i) {
                pages += nums[j];
            } else {
                student++;
                pages = nums[j];
            }
        }
        if (student <= m) {
            return true;
        }

        return false;
    }
    int findPages(vector<int> &nums, int m) {
        if (m > nums.size()) {
            return -1;
        }
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int ans = start;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isValid(nums, m, mid) == true) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};