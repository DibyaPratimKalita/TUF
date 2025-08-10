/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    void solve(TreeNode* node, vector<int>& temp, vector<vector<int>>& ans) {
        if (node == NULL) {
            return;
        }
        temp.push_back(node->data);
        if (node->left == NULL && node->right == NULL) {
            ans.push_back(temp);
        }

        solve(node->left, temp, ans);

        solve(node->right, temp, ans);

        temp.pop_back();
    }
    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, temp, ans);
        return ans;
    }
};