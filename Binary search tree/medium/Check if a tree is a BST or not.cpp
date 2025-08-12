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
        bool check(TreeNode* node, long mini, long maxi){
            if(node==NULL) return true;

            if(node->data >= maxi || node->data <= mini){
                return false;
            }

            bool leftCheck=check(node->left, mini, node->data);
            bool rightCheck=check(node->right, node->data, maxi);

            return leftCheck && rightCheck;
        }
		bool isBST(TreeNode* root){
			return check(root, LONG_MIN, LONG_MAX);
		}
};