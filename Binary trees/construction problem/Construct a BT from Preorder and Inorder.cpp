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
    unordered_map<int,int>mp;
    int idx=0;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        }

        int rootVal = preorder[idx];
        idx++;
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];
        root->left = solve(preorder, inorder, start, pos-1);
        root->right = solve(preorder, inorder, pos+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int  n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int start = 0, end = n-1;
        return solve(preorder, inorder, start, end);
    }
};