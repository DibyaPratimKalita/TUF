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
    vector<int> inorder;
    int idx = 0;

    void recover(TreeNode* node) {
        if (node == NULL) return;

        recover(node->left);
        node->data = inorder[idx];
        idx++;
        recover(node->right);
    }

    void findInorder(TreeNode* node) {
        if (node == NULL) return;

        findInorder(node->left);
        inorder.push_back(node->data);
        findInorder(node->right);
    }

    void recoverTree(TreeNode* root) {
        findInorder(root);
        sort(inorder.begin(), inorder.end());
        recover(root);
    }
};