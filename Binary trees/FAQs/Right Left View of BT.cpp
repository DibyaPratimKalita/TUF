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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while (q.empty() == false) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();

                if (i == size - 1) { // for left view i==0
                    ans.push_back(temp->data);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};