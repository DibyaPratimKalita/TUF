class Solution {
   public:
    typedef pair<int, int>P;
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        // making the graph adj list
        map<int, vector<P>> adj;
        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Dijkstra Algorithm

        vector<int> dis(n + 1, INT_MAX);
        dis[1] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 1});

        vector<int> parent(n + 1, -1);

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int distance = node.first;
            int u = node.second;

            for (auto neighbor : adj[u]) {
                int wt = neighbor.second;
                int v = neighbor.first;
                if (distance + wt < dis[v]) {
                    dis[v] = distance + wt;
                    pq.push({dis[v], v});
                    parent[v] = u;
                }
            }
        }

        if(dis[n]==INT_MAX) return {-1};

        vector<int> ans;
        
        //this logic is very simple use pen paper to understand 
        int dest = n;
        while (dest != -1) {
            ans.push_back(dest);
            dest = parent[dest];
        }

        ans.push_back(dis[n]);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};