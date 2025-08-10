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
    unordered_map<int, TreeNode*> mp;

    void solve(TreeNode* node) {
        if (node == NULL) return;

        if (node->left) {
            mp[node->left->data] = node;
        }
        if (node->right) {
            mp[node->right->data] = node;
        }
        solve(node->left);
        solve(node->right);
    }

    void bfs(TreeNode* target, int k, vector<int>& ans) {
        unordered_set<int> visited;
        visited.insert(target->data);
        queue<TreeNode*> q;
        q.push(target);

        while (q.empty() == false) {
            int size = q.size();
            if (k == 0) break;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != NULL &&
                    visited.count(temp->left->data) == 0) {
                    visited.insert(temp->left->data);
                    q.push(temp->left);
                }
                if (temp->right != NULL &&
                    visited.count(temp->right->data) == 0) {
                    visited.insert(temp->right->data);
                    q.push(temp->right);
                }

                if (mp.count(temp->data) != 0 &&
                    visited.count(mp[temp->data]->data) == 0) {
                    visited.insert(mp[temp->data]->data);
                    q.push(mp[temp->data]);
                }
               
            }
             k--;
        }

        while (q.empty() == false) {
            TreeNode* valNode = q.front();
            q.pop();
            ans.push_back(valNode->data);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // make the node traversable to up
        solve(root);
        vector<int> ans;
        bfs(target, k, ans);
        // for(auto it:mp){
        //     cout<<it.first<<" :"<<it.second<<endl;
        // }
        return ans;
    }
};