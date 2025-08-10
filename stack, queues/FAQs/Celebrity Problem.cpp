class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        
        //for celebrity knowMe = n-1 && I know = 0
        vector<int>knowMe(n);
        vector<int>iKnow(n);

        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j] == 1){
                    iKnow[i]++;
                    knowMe[j]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(iKnow[i]==0 && knowMe[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};
