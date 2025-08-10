class Solution{
    public:
    void solve(int ind, int sum, int &count, vector<int>&nums, int k){
        if(ind==nums.size()){
            if(sum==k){
                count++;
            }
            return;
        }
        sum+=nums[ind];
        solve(ind+1, sum, count, nums, k);
        sum-=nums[ind];

        solve(ind+1, sum, count, nums, k);
    }    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int count=0;
        int sum=0;
        solve(0,sum, count, nums, k);
        return count;
    }
};