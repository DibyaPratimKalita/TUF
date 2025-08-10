class Solution {
public:	
    void solve(int i, vector<int>temp, vector<vector<int>>&ans,vector<int>& nums){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        //not pick
        solve(i+1, temp, ans, nums);

        //take
        temp.push_back(nums[i]);
        solve(i+1, temp, ans, nums); 
    }
    vector<vector<int> > powerSet(vector<int>& nums) {
        //your code goes here
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        solve(0,temp,ans,nums);

        return ans;
    }
};