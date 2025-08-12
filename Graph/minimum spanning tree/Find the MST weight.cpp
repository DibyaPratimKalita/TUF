class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, 0});

        unordered_set<int> visited;

        int mstweight = 0;
        while (pq.empty() == false) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int wt = top.first;

            if(visited.find(node) != visited.end()){
                continue;
            }

            visited.insert(node);
            mstweight += wt;

            for (auto neighbor : adj[node]) {
                int v = neighbor[0];
                int edgewt = neighbor[1];
                if (visited.find(v) == visited.end()) {
                    pq.push({edgewt, v});
                }
            }
        }

        return mstweight;
    }
};
