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
    bool check(TreeNode* node, long mini, long maxi) {
        if (node == NULL) return true;
        
        if (node->data >= maxi || node->data <= mini) {
            return false;
        }
        
        bool leftCheck = check(node->left, mini, node->data);
        bool rightCheck = check(node->right, node->data, maxi);
        
        return leftCheck && rightCheck;
    }
    
    bool isBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    int findSize(TreeNode* node) {
        if (node == NULL) return 0;

        int leftTree=findSize(node->left);
        int rightTree=findSize(node->right);
        
        return 1 + leftTree + rightTree;
    }
    
    void preorder(TreeNode* node, int& maxi) {
        if (node == NULL) return;
        
        if (isBST(node)) {
            maxi = max(maxi, findSize(node));
        }
        
        preorder(node->left, maxi);
        preorder(node->right, maxi);
    }
    
    int largestBST(TreeNode* root) {
        int maxi = 0;
        preorder(root, maxi);
        return maxi;
    }
};