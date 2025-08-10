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
    bool solve(TreeNode* leftNode,TreeNode* rightNode){

        if(leftNode== NULL && rightNode==NULL){
            return true;
        }
        if(leftNode == NULL || rightNode==NULL){
            return false;
        }
        if(leftNode->data!=rightNode->data){
            return false;
        }

        if(solve(leftNode->left,rightNode->right)==false){
            return false;
        }
        if(solve(leftNode->right,rightNode->left)==false){
            return false;
        }

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
};