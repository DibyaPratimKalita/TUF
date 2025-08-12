class Solution {
   public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {

        vector<int> dis(V, 1e9);
        dis[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, S});

        while (!pq.empty()) {
            auto top= pq.top();
            pq.pop();

            int u= top.second;
            int dist=top.first;

            if(dist > dis[u]) continue; //optimization

            for (auto neighbor : adj[u]) {
                int v = neighbor[0];
                int wt = neighbor[1];

                if(dist + wt < dis[v] ){
                    dis[v]=dist + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }
};