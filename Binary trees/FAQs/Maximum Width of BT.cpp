/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
/*     
       0
    1     2
  3   4  5  6
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int normalize = q.front().second;

            int first = 0, last = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                q.pop();

                idx = idx - normalize;

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left) {
                    q.push({node->left, (long long)2 * idx + 1});
                }
                if (node->right) {
                    q.push({node->right,(long long) 2 * idx + 2});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};

/*
Idea is to find the first and last index of each level, we know this
by property 
-> left child = 2* i +1
-> right child = 2* i +2 
where index starts from 0;
ans will be the max of each level (first and last index)

That works but incase the tree goes deep we see interger overflow 
therefore we need to normalize, we bring every level in relative to 0
*/