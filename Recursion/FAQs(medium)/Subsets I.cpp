class Solution {
  public:
    void solve(int ind, int sum, vector<int>&ans, vector<int>nums){
        if(ind==nums.size()){
            ans.push_back(sum);
            return;
        }
        sum+=nums[ind];
        solve(ind+1,sum,ans,nums);
        sum-=nums[ind];

        solve(ind+1, sum, ans, nums);
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        vector<int>ans;
        int sum=0;
        solve(0,sum,ans,nums);
        return ans;
    }
};