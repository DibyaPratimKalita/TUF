class Solution {
public:
    void solve(int ind, vector<int>temp,vector<vector<int>>&ans, vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,temp, ans,nums);
        temp.pop_back();

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }

        solve(ind+1, temp, ans, nums);
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,temp,ans,nums);
        return ans;
    }
};