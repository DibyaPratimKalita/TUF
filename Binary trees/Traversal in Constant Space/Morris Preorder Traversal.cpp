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
    vector<int> preorder(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                // create thread
                if (prev->right == NULL) {
                    prev->right = curr;
                    ans.push_back(curr->data);
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};