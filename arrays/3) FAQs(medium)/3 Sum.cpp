class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int start=i+1, end=n-1;

            while(start<end){
                int sum=nums[start] + nums[end] + nums[i];
                if( sum == 0){
                    ans.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }else if(sum<0){
                    start++;
                }else{
                    end--;
                }
            }
        }
        vector<vector<int>> ans1;
        for(auto it: ans){
            ans1.push_back(it);
        }
        return ans1;
    }
};