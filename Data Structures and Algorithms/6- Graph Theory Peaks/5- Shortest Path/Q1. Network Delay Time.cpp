class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>>g(n + 1);
        for (auto &it : times) {
            int u = it[0], v = it[1], w = it[2];
            g[u].push_back({v, w});
        }
        vector<int>dist(n + 1, 2e9);
        dist[k] = 0;
        queue<int>q;
        q.push(k);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &it : g[cur]) {
                if (dist[it[0]] > dist[cur] + it[1]) {
                    dist[it[0]] = dist[cur] + it[1];
                    q.push(it[0]);
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++)
            mx = max(mx, dist[i]);
        return mx == 2e9 ? -1 : mx;
    }
};