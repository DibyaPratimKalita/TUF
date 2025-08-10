class Solution {
public:

vector<int> inorder(TreeNode* root){
    
    stack<TreeNode*> st;
    
    TreeNode* node = root;
    vector<int> ans;

    while(true){
        // If the current node is not NULL
        if(node != NULL){
            // Push the current
            // node to the stack
            st.push(node);
            // Move to the left child
            // of the current node
            node = node->left;
        }
        else{
            // If the stack is empty,
            // break the loop
            if(st.empty()){
                break;
            }
            // Retrieve a node from the stack
            node = st.top();
            // Remove the node from the stack
            st.pop();
            // Add the node's value to
            // the inorder traversal list
            ans.push_back(node->data);
            // Move to the right child
            // of the current node
            node = node->right;
        }
    }

    return ans;
}
};
