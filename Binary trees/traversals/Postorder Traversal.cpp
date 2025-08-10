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

			
			
			solve(root->left,ans);


			solve(root->right,ans);
			ans.push_back(root->data);

			return;

		}
		vector<int> postorder(TreeNode* root){
	        vector<int>ans;
	     	solve(root,ans);
			return ans;
		}
};