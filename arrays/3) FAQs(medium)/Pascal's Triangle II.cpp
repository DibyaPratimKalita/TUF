class Solution {
public:
    vector<int> pascalTriangleII(int r) {
        vector<vector<int>> pascal(r);

        for (int i = 0; i < r; i++) {
            pascal[i] = vector<int>(i + 1, 1);
            for (int j = 1; j <= i - 1; j++) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal[r-1];
    }
};