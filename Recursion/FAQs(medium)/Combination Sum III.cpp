class Solution {
public:
    void solve(int ind,int sum, vector<int> temp, vector<vector<int>>&ans, vector<int>&candidates, int target,int k){
        if (sum == target) {  // Base case: valid combination found
            if(k==0){
                ans.push_back(temp);    
            }
            return;    
        }
        if (sum > target || ind == candidates.size()) {  // Base case: sum exceeded or no more candidates
            return;
        }
        
        sum+=candidates[ind];
        temp.push_back(candidates[ind]);
        solve(ind+1,sum, temp, ans, candidates, target,k-1);
        sum-=candidates[ind];
        temp.pop_back();

        solve(ind+1,sum, temp,ans, candidates, target,k);
    }
    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(0,sum,temp,ans,candidates,n,k);

        return ans;    
    }
};