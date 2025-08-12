class Solution {
   public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        map<int, vector<int>> reverseAdj;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                int u = i;
                int v = adj[i][j];
                reverseAdj[v].push_back(u);
            }
        }
        vector<int> indeg(V, 0);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < reverseAdj[i].size(); j++) {
                indeg[reverseAdj[i][j]]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int>ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int neighbor : reverseAdj[node]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};