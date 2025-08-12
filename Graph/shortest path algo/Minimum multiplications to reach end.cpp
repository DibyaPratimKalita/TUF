class Solution {
   public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        int mod = 1e5;
        queue<int> q;
        q.push(start);
        vector<bool> visited(mod, false);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int node = q.front();
                q.pop();

                if (node == end) return level;
                for (int i : arr) {
                    int neighbor = (i * node) % mod;
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
