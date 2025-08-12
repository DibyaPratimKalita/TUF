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
    TreeNode* build(vector<int>& preorder, int &idx, int upperBound){
        if(idx >= preorder.size() || preorder[idx] >= upperBound){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[idx]);
        idx++;
        root->left=build(preorder,idx, root->data);
        root->right=build(preorder,idx, upperBound);

        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;

        return build(preorder, idx, INT_MAX);
    }
};