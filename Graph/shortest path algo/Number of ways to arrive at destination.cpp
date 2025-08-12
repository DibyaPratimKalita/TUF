class Solution {
   public:
    int countPaths(int n, vector<vector<int>> &roads) {
        int mod=1e9+7;
        map<int, vector<pair<int, int>>> adj;
        for (auto ele : roads) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int dis = node.first;
            int u = node.second;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int wt = neighbor.second;

                if (dis + wt < dist[v]) {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                    ways[v] = ways[u];
                } else if (dis + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        if (ways[n - 1] == 0 ) return 0;
        return ways[n - 1];
    }
};