class Solution {
   public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        int min = 0;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();

			bool detect=false;
            while (size--) {
                auto node = q.front();
                q.pop();
                for (auto ele : dir) {
                    int x_new = ele.first + node.first;
                    int y_new = ele.second + node.second;

                    if (x_new >= 0 && x_new < grid.size() && y_new >= 0 &&
                        y_new < grid[0].size() && grid[x_new][y_new] == 1) {
                        grid[x_new][y_new] = 2;
                        q.push({x_new, y_new});
                        freshOranges--;
						detect=true;
                    }
                }
            }
			if(detect==true)
				min++;
        }

		if(freshOranges==0){
			return min;
		}

		return -1;
    }
};