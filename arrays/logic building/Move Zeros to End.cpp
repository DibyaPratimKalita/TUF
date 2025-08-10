class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // j points to where the next non-zero should be placed
        int j = 0;

        // Traverse all elements
        for (int i = 0; i < nums.size(); i++) {
            // If current element is non-zero
            if (nums[i] != 0) {
                // Swap it with the element at index j
                swap(nums[i], nums[j]);

                // Move j to next position
                j++;
            }
        }
    }
};
