class Solution {
   public:
    vector<vector<char>> fill(vector<vector<char>> mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<char>> ans(m, vector<char>(n, 'X'));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (mat[i][j] == 'O') {
                        ans[i][j] = 'O';
                        mat[i][j]='#';
                        q.push({i, j});
                    }
                }
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto ele : dir) {
                int x_new = ele.first + node.first;
                int y_new = ele.second + node.second;

                if (x_new >= 0 && x_new < mat.size() && y_new >= 0 &&
                    y_new < mat[0].size() && mat[x_new][y_new] == 'O') {
                    ans[x_new][y_new] = 'O';
                    mat[x_new][y_new]='#';
                    q.push({x_new, y_new});
                }
            }
        }
        return ans;
    }
};

