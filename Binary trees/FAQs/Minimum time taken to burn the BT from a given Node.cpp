/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int data) : data(data) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    unordered_set<TreeNode*> visited;
    // child to parent
    unordered_map<TreeNode*, TreeNode*> mp;

    void parentFilling(TreeNode* node) {
        if (node == NULL) return;

        if (node->left) {
            mp[node->left] = node;
        }
        if (node->right) {
            mp[node->right] = node;
        }

        parentFilling(node->left);
        parentFilling(node->right);
    }

    void bfs(TreeNode* startAddress, int& level) {
        if (startAddress == NULL) return;

        queue<TreeNode*> q;
        q.push(startAddress);
        visited.insert(startAddress);

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* front = q.front();
                q.pop();

                // left explore
                if (front->left && visited.count(front->left) == 0) {
                    visited.insert(front->left);
                    q.push(front->left);
                }
                // right explore
                if (front->right && visited.count(front->right) == 0) {
                    visited.insert(front->right);
                    q.push(front->right);
                }

                // up check (parent check)
                if (mp.find(front) != mp.end() &&
                    visited.count(mp[front]) == 0) {
                    TreeNode* parent = mp[front];
                    visited.insert(parent);
                    q.push(parent);
                }
            }
            level++;
        }
    }
    TreeNode* findAddress(TreeNode* node, int start) {
        if (node == NULL) return NULL;

        if (node->data == start) {
            return node;
        }
        TreeNode* left = findAddress(node->left, start);
        TreeNode* right = findAddress(node->right, start);

        if (left) return left;
        return right;
    }
    int timeToBurnTree(TreeNode* root, int start) {
        if (root == NULL) return 0;
        parentFilling(root);
        TreeNode* startAddress = NULL;
        if (start == root->data) {
            startAddress = root;
        } else {
            startAddress = findAddress(root, start);
        }

        int level = 0;
        bfs(startAddress, level);
        return level - 1;
    }
};