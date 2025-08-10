class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        int numSum = 0;
        for (auto ele : nums) {
            numSum += ele;
        }

        return sum - numSum;
    }
};