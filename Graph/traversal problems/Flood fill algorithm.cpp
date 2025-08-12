class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>> &ans, int newColor,
             int prevColor) {
        if (i < 0 || i >= ans.size() || j < 0 || j >= ans[0].size() ||
            ans[i][j] != prevColor) {
            return;
        }

        ans[i][j] = newColor;

        dfs(i - 1, j, ans, newColor, prevColor);
        dfs(i + 1, j, ans, newColor, prevColor);
        dfs(i, j - 1, ans, newColor, prevColor);
        dfs(i, j + 1, ans, newColor, prevColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }
        int m = image.size(), n = image[0].size();
        vector<vector<int>> ans = image;

        int prevColor = ans[sr][sc];
        dfs(sr, sc, ans, newColor, prevColor);

        return ans;
    }
};
