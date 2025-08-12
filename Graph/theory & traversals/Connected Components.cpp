class Solution {
   public:
    void dfs(unordered_set<int> &visited, int i, unordered_map<int, vector<int>>& adj){
        // if(visited.count(i)==1){
        //     return;
        // }
        visited.insert(i);

        for(int neighbor: adj[i]){
            if(visited.count(neighbor)==0)
                dfs(visited,neighbor,adj);
        }
    }
    int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;
        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> visited;

        int compo = 0;
        for (int i = 0; i < V; i++) {
            if(visited.count(i)==0){
                dfs(visited, i, adj);
                compo++;
            }
               
        }

        return compo;
    }
};