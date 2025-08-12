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
        void inorder(TreeNode* node,int key, int &predecessor, int &successor){
            if(node==NULL){
                return;
            }
            
            inorder(node->left,key, predecessor, successor);

            if(successor != -1) return;
            
            if(node->data<key){
                predecessor=node->data;
            }
            else if(node->data > key){
                successor=node->data;
                return;
            }
            inorder(node->right,key, predecessor, successor);
        }
		vector<int> succPredBST(TreeNode* root,int key){
			//brute force
            
            int predecessor=-1,successor=-1;
            inorder(root,key,predecessor,successor);
           
            return {predecessor,successor};
		}
};