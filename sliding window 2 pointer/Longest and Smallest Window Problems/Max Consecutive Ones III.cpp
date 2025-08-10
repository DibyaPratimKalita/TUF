class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //find longest substring with k max zeroes 
        int left = 0, right = 0;
        int zeroesTillNow = 0;
        int maxlen = 0;
        int n = nums.size();
        while(right < n){
            if(nums[right] == 0){
                zeroesTillNow++;
                while(zeroesTillNow > k){
                    if(nums[left] == 0){
                        zeroesTillNow--;
                    }
                    left++;
                }
            }

            maxlen = max(maxlen, right - left +1);
            right ++;
        }

        return maxlen;
    }
};