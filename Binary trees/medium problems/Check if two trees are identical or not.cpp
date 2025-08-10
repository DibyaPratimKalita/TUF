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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p==NULL && q!=NULL)||(p && q==NULL)){
            return false;
        }
        if(p->data!=q->data) return false;
        if(isSameTree(p->left,q->left)==false){
            return false;
        }
        if(isSameTree(p->right,q->right)==false){
            return false;
        };
        return true; 
    }
};