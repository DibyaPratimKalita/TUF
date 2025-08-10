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
    int idx;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        }

        int rootVal = preorder[idx];
        idx--;
        TreeNode* root = new TreeNode(rootVal);

        int pos = mp[rootVal];
        root->right = solve(preorder, inorder, pos+1, end);
        root->left = solve(preorder, inorder, start, pos-1);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int start=0, end=n-1;
        idx=n-1;
        return solve(postorder, inorder, start, end);
    }
};