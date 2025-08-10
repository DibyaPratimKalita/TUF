class Solution {
   public:
    int subarraySum(vector<int> &nums, int k) {
        // prefix sum to frequency
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0]=1; // for the case [1,1,1,1], K=2 do dry run 
        int count = 0;

        for (int i = 0; i < n; i++) {
            sum +=nums[i];

            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[sum]++;
        }
        return count;
    }
};