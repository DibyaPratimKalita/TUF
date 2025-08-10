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
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        // map to store x axis vertical line and the node value
        map<int, int> mp;
        // queue to store the node and the x axis vertical line
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (q.empty() == false) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second;

            // if (mp.find(x) == mp.end()) {
            //     mp[x] = node->data;
            // }
            mp[x] = node->data;
            if (node->left) {
                q.push({node->left, x - 1});
            }
            if (node->right) {
                q.push({node->right, x + 1});
            }
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};