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
		vector<vector<int> > treeTraversal(TreeNode* root){
			vector<int>pre,inor, post;
            stack<pair<TreeNode*,int>>st;
            st.push({root,1});
            while(st.empty()==false){
                auto curr=st.top();
                st.pop();

                if(curr.second==1){
                    pre.push_back(curr.first->data);
                    ++curr.second;
                    st.push(curr);

                    if(curr.first->left!=NULL){
                        st.push({curr.first->left,1});
                    }
                }
                else if(curr.second==2){
                    inor.push_back(curr.first->data);
                    ++curr.second;
                    st.push(curr);

                    if(curr.first->right!=NULL){
                        st.push({curr.first->right,1});
                    }
                }
                else{
                    post.push_back(curr.first->data);
                }
            }
            vector<vector<int>>ans={{inor},{pre},{post}};

            return ans;
		}
};