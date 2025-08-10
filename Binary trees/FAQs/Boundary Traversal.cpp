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
    bool isLeaf(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            return true;
        }
        return false;
    }
    void addLeftBoundary(TreeNode* node, vector<int>& ans) {
        node=node->left;
        while (node != NULL) {
            if (isLeaf(node) == false) {
                ans.push_back(node->data);
            }
            if (node->left) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    void addLeaves(TreeNode* node, vector<int>& ans) {
        if (isLeaf(node) == true) {
            ans.push_back(node->data);
            return;
        }
        if (node->left) addLeaves(node->left, ans);
        if (node->right) addLeaves(node->right, ans);
    }

    void addRightBoundary(TreeNode* node, vector<int>& ans) {
        node=node->right;
        vector<int>temp;
        while (node) {
            if (isLeaf(node) == false) {
                temp.push_back(node->data);
            }
            if(node->right){
                node=node->right;
            }else{
                node=node->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    vector<int> boundary(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if(isLeaf(root)==false){
            ans.push_back(root->data);
        }
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};