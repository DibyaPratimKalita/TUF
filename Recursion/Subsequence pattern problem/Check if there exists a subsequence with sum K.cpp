class Solution{
    public:
    bool solve(int ind, int sum, vector<int>&nums, int k){
        if(ind==nums.size()){
            if(sum==k){
                return true;
            }
            return false;
        }
        sum+=nums[ind];
        if(solve(ind+1, sum, nums, k)==true){
            return true;
        }
        sum-=nums[ind];

        solve(ind+1, sum, nums, k);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int sum=0;
       return solve(0, 0,nums,k);  
    }
};