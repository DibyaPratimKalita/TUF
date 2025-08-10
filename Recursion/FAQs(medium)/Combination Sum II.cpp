class Solution {
public:
    void solve(int ind,int sum, vector<int> &temp, vector<vector<int>>&ans, vector<int>&candidates, int target){
        if (sum == target) {  // Fix base condition
            ans.push_back(temp);
            return;
        }
        if (ind == candidates.size() || sum > target) return; // Fix condition

        sum+=candidates[ind];
        temp.push_back(candidates[ind]);
        solve(ind+1,sum, temp, ans, candidates, target);
        sum-=candidates[ind];
        temp.pop_back();

        for(int i = ind + 1; i < candidates.size(); i++) {
            if(candidates[i] != candidates[ind]) {
                solve(i,sum, temp,ans, candidates, target);
                break; 
            }
        }

        
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        int sum=0;
        solve(0,0, temp,ans,candidates,target);

        return ans;
    }
};