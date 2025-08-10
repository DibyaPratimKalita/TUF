class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(auto &vec: matrix){
            reverse(vec.begin(), vec.end());
        }
    }
};

/*

1 2 3 
4 5 6 
7 8 9

1 4 7 
2 5 8
3 6 9

*/