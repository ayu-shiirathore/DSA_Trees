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
    int maxDepth(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lev_size=q.size();
            vector<int> level;
            for(int i=0;i<lev_size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans.size();
    }
};