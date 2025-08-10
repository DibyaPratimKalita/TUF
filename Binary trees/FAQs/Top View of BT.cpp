/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    public:
    vector<int> topView(TreeNode *root){
        map<int,int> mp;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});

        while(!q.empty()){
            TreeNode* node = q.front().second;
            int x = q.front().first;
            q.pop();

            if(mp.find(x) == mp.end()){
                mp[x] = node->data;
            }

            if(node->left){
                q.push({x-1, node->left});
            }
            if(node->right){
                q.push({x+1, node->right});
            }
        }

        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};