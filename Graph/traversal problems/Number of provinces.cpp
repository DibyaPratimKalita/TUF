class Solution {
   public:
    void dfs(int i, unordered_map<int, vector<int>>& adjlist,
             unordered_set<int>& visited) {
        if (visited.count(i) == 1) {
            return;
        }
        visited.insert(i);

        for (auto neighbors : adjlist[i]) {
            if (visited.count(neighbors) == 0) {
                dfs(neighbors, adjlist, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj) {
        int V = adj.size();
        unordered_map<int, vector<int>> adjlist;

        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[0].size(); j++) {
                if (i != j && adj[i][j] == 1) {
                    int u = i + 1;
                    int v = j + 1;
                    adjlist[u].push_back(v);
                    adjlist[v].push_back(u);
                }
            }
        }
        unordered_set<int> visited;
        int count = 0;
        for (int i = 1; i <= V; i++) {
            if (visited.count(i) == 0) {
                dfs(i, adjlist, visited);
                count++;
            }
        }

        return count;
    }
};
