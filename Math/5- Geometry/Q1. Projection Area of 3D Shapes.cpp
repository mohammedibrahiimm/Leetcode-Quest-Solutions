class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt = 0, ans = 0;
        const int n = grid.size();
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < n; j++) {
                cnt += grid[i][j] != 0;
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        return ans + cnt;
    }
};