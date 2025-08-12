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
    void inorder(TreeNode* node, vector<int>&ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,ans);
        ans.push_back(node->data);
        inorder(node->right,ans);
    }
	vector<int> kLargesSmall(TreeNode* root,int k){
		vector<int>ans;
        inorder(root,ans);
        return {ans[k-1],ans[ans.size()-k]};

	}
};