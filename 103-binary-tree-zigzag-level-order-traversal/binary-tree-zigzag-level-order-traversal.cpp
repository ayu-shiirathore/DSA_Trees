/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
        return ans;
        q.push(root);
        bool lefttoRight=true;

        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++){
                TreeNode* node= q.front();
                q.pop();

                //find position to fill nodes value
                int index = lefttoRight ? i : (size-1-i);
                row[index]=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }

             //after this level 
                lefttoRight=!lefttoRight;
                //push the row
                ans.push_back(row);

        }
        
        return ans;

    }
};