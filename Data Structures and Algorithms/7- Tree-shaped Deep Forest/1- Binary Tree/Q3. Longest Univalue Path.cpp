class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        int leftPath = 0, rightPath = 0;
        if (root->left && root->left->val == root->val)
            leftPath = L + 1;
        if (root->right && root->right->val == root->val)
            rightPath = R + 1;
        ans = max(ans, leftPath + rightPath);
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};