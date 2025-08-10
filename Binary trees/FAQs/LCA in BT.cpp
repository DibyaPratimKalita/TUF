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
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return NULL;
        
        if(node == p || node == q){
            return node;
        }

        TreeNode* left = solve(node->left, p, q);
        TreeNode* right = solve(node->right, p, q);

        if(left != NULL && right != NULL){
            return node;
        }
        if(right == NULL){
            return left;
        }
        if(left == NULL){
            return right;
        }

        return NULL;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};