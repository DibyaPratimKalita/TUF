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
    vector<int> getInorder(TreeNode* root) {
    	TreeNode* curr=root;
        vector<int>ans;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right != NULL){
                    prev=prev->right;
                }

                //create thread
                prev->right = curr;
                
                //delete old thred to left
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }

        return ans;
    }
};