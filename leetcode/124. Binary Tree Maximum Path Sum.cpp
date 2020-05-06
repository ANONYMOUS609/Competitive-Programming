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
    int ans = INT_MIN;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;
        int x = solve(root->left);
        int y = solve(root->right);
        ans = max(ans,root->val + max(x,max(y,max(x+y,0))));
        return max(x,max(y,0))+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};