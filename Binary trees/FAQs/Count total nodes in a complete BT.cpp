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
    void preOrder(TreeNode* node, int &count){
        if(node==NULL) return;

        count++;
        preOrder(node->left,count);
        preOrder(node->right,count);
    }
    int countNodes(TreeNode* root) { 
       int count=0;
       preOrder(root,count);
       return count;
    }
};