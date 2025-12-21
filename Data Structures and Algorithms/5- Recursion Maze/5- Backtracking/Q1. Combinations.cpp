class Solution {
public:
    vector<vector<int>>ans;
    vector<int>use;
    void solve(int i, int n, int k) {
        if (i == n + 1) {
            if (use.size() == k)ans.push_back(use);
            return;
        }
        use.push_back(i);
        solve(i + 1, n, k);
        use.pop_back();
        solve(i + 1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k);
        return ans;
    }
};