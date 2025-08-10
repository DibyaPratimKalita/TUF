class Solution {
   public:
    int findFirstOccurence(vector<int> &arr) {
        int start = 0, end = arr.size() - 1;
        int first = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= 1) {
                first = mid;
                end = mid - 1;

            } else if (arr[mid] == 0) {
                start = mid + 1;
            }
        }

        return first;
    }
    int rowWithMax1s(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();
        int ansind = -1;
        int maxOnes = 0;
        for (int i = 0; i < r; i++) {
            int firstOne = findFirstOccurence(mat[i]);
            int ones = (firstOne == -1) ? 0 : mat[i].size() - firstOne;
            if (ones > maxOnes) {
                ansind = i;
                maxOnes = ones;
            }
        }
        return ansind;
    }
};