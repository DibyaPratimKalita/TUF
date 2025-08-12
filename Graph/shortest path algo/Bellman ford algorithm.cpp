class Solution {
   public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V, 1e9);
        distance[S] = 0;
        // n-1 times on the edges
        for (int i = 0; i < V - 1; i++) {
            for (auto ele : edges) {
                int u = ele[0];
                int v = ele[1];
                int wt = ele[2];

                if (distance[u]!=1e9 && (distance[u] + wt < distance[v])) {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        // for checking negative cycle one more times
        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            if (distance[u]!=1e9 && (distance[u] + wt < distance[v])) {
                return {-1};
            }
        }

        return distance;
    }
};
