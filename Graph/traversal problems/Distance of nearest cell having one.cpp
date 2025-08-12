class Solution {
   public:
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> mat(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.empty() == false) {
            auto front = q.front();
            q.pop();

            mat[front.second.first][front.second.second] = front.first;
            for (auto dir : dirs) {
                int new_i = front.second.first + dir[0];
                int new_j = front.second.second + dir[1];
                int dis = front.first;
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    visited[new_i][new_j] == false) {
                    visited[new_i][new_j] = true;
                    q.push({dis + 1, {new_i, new_j}});
                }
            }
            
        }
        return mat;

    }
};