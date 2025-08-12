/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator{
	public:
        stack<TreeNode*>st;

        void pushAllLeft(TreeNode* node){
            while(node!=NULL){
                st.push(node);
                node=node->left;
            }
        }

		BSTIterator(TreeNode* root){
            pushAllLeft(root);
		}
		
		bool hasNext(){
			if(st.empty()==true){
                return false;
            }else{
                return true;
            }
		}
		
		int next(){
            TreeNode* valueNode=st.top();
            st.pop();
            pushAllLeft(valueNode->right);
            return valueNode->data;
		}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */