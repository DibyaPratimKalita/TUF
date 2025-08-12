class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<int>dis(N,-1);
        map<int,vector<int>>adj;

        for(vector<int> ele : edges){
            int u=ele[0];
            int v=ele[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(N,false);
        dis[0]=0;
        visited[0]=true;

        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int neighbor: adj[node]){
                if(visited[neighbor]==false){
                    dis[neighbor]=dis[node]+1;
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }

        return dis;
    }
};
