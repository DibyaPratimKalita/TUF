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
		void solve(TreeNode* root, vector<int> &ans){
			if(root==NULL) return ;

			
			ans.push_back(root->data);
			solve(root->left,ans);


			solve(root->right,ans);

		}
		vector<int> preorder(TreeNode* root){
	       vector<int>ans;
	     	solve(root,ans);
			return ans;
		}
};