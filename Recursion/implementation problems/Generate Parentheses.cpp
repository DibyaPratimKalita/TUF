class Solution {
public:
    void solve(vector<string>&ans, string temp, int n, int open, int closed){

        if(open==n && closed==n){
            ans.push_back(temp);
            return;
        }
        if(open<n){
            solve(ans,temp+'(',n,open+1,closed);
        }
        if(closed<open){
            solve(ans,temp+')',n, open, closed+1);
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string temp="";
       solve(ans,temp,n,0,0);
       return ans;
    }
};