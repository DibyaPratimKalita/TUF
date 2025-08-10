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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;
        while (q.empty() == false) {
            int size = q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++) {
                TreeNode* front = q.front();
                q.pop();
                if(leftToRight == false){
                    temp[size -1 - i] = front->data;
                }else{
                    temp[i] = front->data;
                }

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};