class Solution {
   public:
    void dfs3(int node, map<int, vector<int>> &revAdj, vector<bool> &visited){
        visited[node] = true;

        for (int neighbor : revAdj[node]) {
            if (visited[neighbor] == false) {
                dfs3( neighbor, revAdj, visited);
            }
        }
    }
    void dfs1(stack<int> &st, vector<bool> &visited, int node,
              vector<int> adj[]) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == false) {
                dfs1(st, visited, neighbor, adj);
            }
        }

        st.push(node);
    }
    int kosaraju(int V, vector<int> adj[]) {
        // step1 sort the orderd of visited
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                dfs1(st, visited, i, adj);
            }
        }

        // step2 reverse the graph
        map<int, vector<int>> revAdj;

        for (int i = 0; i < V; i++) {
            visited[i]=false; //just reseting the visited array
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                int u = i;
                revAdj[v].push_back(u);
            }
        }

        // step3 do dfs in order of stack
        int scc = 0;
        while (!st.empty()) {
            int top = st.top();
            st.pop();

            if (visited[top] == false) {
                dfs3(top, revAdj, visited);
                scc++;
            }
        }

        return scc;
    }
};
