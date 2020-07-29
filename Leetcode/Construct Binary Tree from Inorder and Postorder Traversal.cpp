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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        int root_val = *postorder.rbegin();
        postorder.pop_back();
        TreeNode* root = new TreeNode(root_val);
        int ind = 0;
        vector<int> in_left, in_right;
        for (int i = 0; i < inorder.size(); i++){
            if (inorder[i] == root_val) {
                ind = 1;
                // break;
            }
            else if (ind == 0) in_left.push_back(inorder[i]);
            else in_right.push_back(inorder[i]);
        }
        // cout << root_val << endl;
        root->right = buildTree(in_right, postorder);
        // for (auto x: in_left) cout << x << " ";
        root->left = buildTree(in_left, postorder);
        
        
        return root;
    }
};