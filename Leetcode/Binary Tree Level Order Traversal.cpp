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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if (root == nullptr){
            return ans;
        }
        qu.push(root);
        qu.push(nullptr);
        vector<int> tmp;
        while(!qu.empty()){
            auto x = qu.front();
            qu.pop();
            if (x == nullptr){
                ans.push_back(tmp);
                tmp.clear();
                if (qu.empty()){
                    break;
                }
                qu.push(nullptr);
                continue;
            }
            tmp.push_back(x->val);
            if (x->left) qu.push(x->left);
            if (x->right) qu.push(x->right);
            
        }
        return ans;
        
    }
};