class Solution {
   public:
    void dfs(int i, int j, vector<vector<bool>>& visited,
             vector<vector<char>>& grid) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() ||
            visited[i][j] == true || grid[i][j] == '0') {
            return;
        }

        visited[i][j] = true;

        // up
        dfs(i - 1, j, visited, grid);

        // down
        dfs(i + 1, j, visited, grid);

        // left
        dfs(i, j - 1, visited, grid);

        // right
        dfs(i, j + 1, visited, grid);

        // top right
        dfs(i - 1, j + 1, visited, grid);

        // top left
        dfs(i - 1, j - 1, visited, grid);

        // bottom right
        dfs(i + 1, j + 1, visited, grid);

        // bottom left
        dfs(i + 1, j - 1, visited, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    if (visited[i][j] == false) {
                        dfs(i, j, visited, grid);
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
