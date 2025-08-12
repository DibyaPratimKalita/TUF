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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        
        while(true){
            if(node->data<val){
                if(node->right==NULL){
                    node->right=new TreeNode(val);
                    break;
                }
                node=node->right;
            }else{
                if(node->left==NULL){
                    node->left=new TreeNode(val);
                    break;
                }
                node=node->left;
            }
        }
        return root;
        
    }
};