class Solution{
public:
    bool isValid(map<int,vector<int>>&adj, int node, int col, vector<int>&color){
        for(int neighbor:adj[node]){
            if(color[neighbor]==col){
                return false;
            }
        }
        return true;

    }
    bool solve(int node, map<int,vector<int>>&adj, int m, int n,vector<int>&color){
        if(node==n){
            return true;
        }

        for(int col=0;col<m;col++){
            if(isValid(adj,node,col,color)==true){
                color[node]=col;

                bool check=solve(node+1,adj,m,n,color);
                if(check==true){
                    return true;
                }
                color[node]=-1;
            }
        }

        return false;

    }
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//rule 1 : always convert graph problems to adj list 
        map<int,vector<int>>adj;
        for(auto ele : edges){
            int u=ele[0];
            int v=ele[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n,-1);
        return solve(0,adj,m,n,color);

    }
};