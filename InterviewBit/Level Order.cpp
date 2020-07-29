/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* root, int level, vector<vector<int> >& ans){
    if (level == ans.size()){
        ans.push_back(vector<int>());
    }
    ans[level].push_back(root->val);
    if (root->left) helper(root->left, level + 1, ans);
    if (root->right) helper(root->right, level + 1, ans);
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector< vector< int > > answer{};
    if (A==NULL) return answer;
    helper(A, 0, answer);
    return answer;
}





