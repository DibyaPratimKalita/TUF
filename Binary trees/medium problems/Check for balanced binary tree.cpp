/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    int check(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int left=check(node->left);
        int right=check(node->right);

        if(left==-1 || right==-1){
            return -1;
        }
        if(abs(left-right)>=2){
            return -1;
        }

        return 1+max(left,right);
        
    }
    bool isBalanced(TreeNode *root){
    	if(check(root)==-1){
            return false;
        }

        return true;
    }
};