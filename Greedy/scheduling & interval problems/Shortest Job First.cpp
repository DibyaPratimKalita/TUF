class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());

        int n=bt.size();
        long long totaltime=0;
        long long waittime=0;
        
        for(int i=0;i<n;i++){
          
          waittime+=totaltime;
          totaltime+=bt[i];
        }
        return waittime/n;
    }
};