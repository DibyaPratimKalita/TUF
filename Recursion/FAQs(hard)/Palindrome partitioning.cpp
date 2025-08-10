class Solution {
public:
    bool isPal(string s, int i, int ind){
        int start=ind, end=i;
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string> &temp,string s, int ind){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPal(s,i,ind)==true){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(ans,temp,s,i+1);
                temp.pop_back(); 
            }
        }
    }
    vector<vector<string> > partition(string s) {
        vector<vector<string>>ans;
        vector<string> temp;
        solve(ans,temp,s,0);
        return ans;
    }
};