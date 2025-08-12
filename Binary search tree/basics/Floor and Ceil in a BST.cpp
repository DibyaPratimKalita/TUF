/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    void findCeil(int& ceil, TreeNode* node, int key) {
        if (node == NULL) return;

        while (node != NULL) {
            if (node->data == key) {
                ceil = key;
                return;
            }
            if (node->data > key) {
                ceil = node->data;
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    void findFloor(int& floor, TreeNode* node, int key) {
        if (node == NULL) return;

        while (node != NULL) {
            if (node->data == key) {
                floor = key;
                return;
            }
            if (node->data < key) {
                floor = node->data;
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        vector<int> ans;
        int ceil = -1;
        int floor = -1;
        findCeil(ceil, root, key);
        findFloor(floor, root, key);
        ans = {floor, ceil};
        return ans;
    }
};