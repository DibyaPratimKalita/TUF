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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }
        queue<TreeNode*> q;
        string data = "";
        q.push(root);
        while (q.empty() == false) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                data += "#,";
            } else {
                data += to_string(temp->data);
                data += ',';
            }

            if (temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        //to remove last ,
        data.pop_back();
        return data;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        // stringstream or breaking string in ,
        vector<string> finalData;
        string temp;
        for (char ch : data) {
            if (ch == ',') {
                finalData.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }
        if (temp.size() != 0) {
            finalData.push_back(temp);
        }
        //done
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(finalData[0]));
        q.push(root);
        int idx=1;
        while(q.empty()==false && idx<finalData.size()){
            TreeNode* curr=q.front();
            q.pop();

            if(finalData[idx]!="#"){
                TreeNode* leftChild=new TreeNode(stoi(finalData[idx]));
                curr->left=leftChild;
                q.push(leftChild);
            }
            idx++;
            if(idx<finalData.size() && finalData[idx]!="#"){
                TreeNode* rightChild=new TreeNode(stoi(finalData[idx]));
                curr->right=rightChild;
                q.push(rightChild);
            }
            idx++;
        }
        return root;
    }
};

/*
 * Your Codec object will be instantiated and called as such:
 * Codec* ser = new Codec();
 * Codec* deser = new Codec();
 * string tree = ser->serialize(root);
 * TreeNode* ans = deser->deserialize(tree);
 * return ans;
 */