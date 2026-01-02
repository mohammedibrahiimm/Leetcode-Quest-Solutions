class Solution {
private:
    TreeNode* findmin(TreeNode* root, int key) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if (root->left == NULL) {
                struct TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                struct TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else {
                struct TreeNode* temp = findmin(root->right, key);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }
};