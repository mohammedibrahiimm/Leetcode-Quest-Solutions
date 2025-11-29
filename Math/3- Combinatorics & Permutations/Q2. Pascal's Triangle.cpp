class Solution {
public:
    vector<vector<int>> generate(int n) {
        if (n == 1)return {{1}};
        vector<vector<int>>ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        for (int i = 2; i < n; i++) {
            ans.push_back({1});
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};