class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* copy = root;
        if (copy == NULL)return new TreeNode(val);
        while (true) {
            if (copy->val < val) {
                if (copy->right == NULL) {
                    copy->right = new TreeNode(val);
                    break;
                } else {
                    copy = copy->right;
                }
            } else {
                if (copy->left == NULL) {
                    copy->left = new TreeNode(val);
                    break;
                } else {
                    copy = copy->left;
                }
            }
        }
        return root;
    }
};