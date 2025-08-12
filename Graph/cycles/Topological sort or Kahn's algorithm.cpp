/*
0-
1-
2-3
4-0,1
5-0,2
*/

class Solution {
   public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        // calculate inDegree
        vector<int> inDegree(V);

        for (int i = 0; i < V; i++) {
            for (int num : adj[i]) {
                inDegree[num]++;
            }
        }

        // do bfs from the 0th inDegree
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for (int neighbors : adj[front]) {
                inDegree[neighbors]--;
                if (inDegree[neighbors] == 0) {
                    q.push(neighbors);
                }
            }
        }

        return ans;
    }
};
