class Solution {
   public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // steps relax the edges based on the topological order

        map<int, vector<pair<int, int>>> adj;

        for (auto ele : edges) {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];
            adj[u].push_back({v, wt});
        }

        vector<int> inDegre(N);

        for (auto it : adj) {
            for (pair<int, int> num : it.second) {
                inDegre[num.first]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < inDegre.size(); i++) {
            if (inDegre[i] == 0) {
                q.push(i);
            }
        }

        // dist array
        vector<int> dist(N, 1e9);
        int src = 0;
        dist[src] = 0;

        while (q.empty() == false) {
            int front = q.front();
            q.pop();

            // Relaxing
            for (pair<int, int> neighbor : adj[front]) {
                int v = neighbor.first;
                int wt = neighbor.second;
                if (dist[front] + wt < dist[v]) {
                    dist[v] = dist[front] + wt;
                }
                inDegre[v]--;
                if (inDegre[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
