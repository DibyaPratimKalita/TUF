/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int data) : data(data) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    unordered_set<int> st;

    bool inorder(TreeNode* node, int k) {
        if (node == NULL) {
            return false;
        }
        if (inorder(node->left, k) == true) {
            return true;
        }

        if (st.find(k - node->data) != st.end()) {
            return true;
        }
        st.insert(node->data);

        if (inorder(node->right, k) == true) {
            return true;
        }
        return false;
    }

    bool twoSumBST(TreeNode* root, int k) { return inorder(root, k); }
};