class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* ans = new TreeNode();
        TreeNode* use = ans;
        int root = -1;
        unordered_map<int, int>in, right, left;
        for (auto &it : descriptions) {
            if (it[2])left[it[0]] = it[1];
            else right[it[0]] = it[1];
            in[it[1]]++;
        }
        for (auto &it : descriptions) if (!in[it[0]]) root = it[0];
        queue<int>q;
        q.push(root);
        unordered_map<int, TreeNode*>nodes;
        nodes[root] = use;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            TreeNode* curNode = nodes[cur];
            curNode->val = cur;
            if (right.count(cur)) {
                curNode->right = new TreeNode();
                nodes[right[cur]] = curNode->right;
                q.push(right[cur]);
            }
            if (left.count(cur)) {
                curNode->left = new TreeNode();
                nodes[left[cur]] = curNode->left;
                q.push(left[cur]);
            }
        }
        return ans;
    }
};