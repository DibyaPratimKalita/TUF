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
    int solve(TreeNode* node, int &ans){
        if(node==NULL) return 0;

        int left=max(0,solve(node->left,ans));
        int right=max(0,solve(node->right,ans));

        ans=max(ans,left+right+ node->data);

        return node->data + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};	