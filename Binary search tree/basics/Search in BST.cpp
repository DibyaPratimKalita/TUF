/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
    	TreeNode* node=root;
        if(node==NULL) return NULL;
        while(node!=NULL){
            if(node->data==val){
                return node;
            }
            if(node->data<val){
                node=node->right;
            }else{
                node=node->left;
            }
        }
        return NULL;
    }
};