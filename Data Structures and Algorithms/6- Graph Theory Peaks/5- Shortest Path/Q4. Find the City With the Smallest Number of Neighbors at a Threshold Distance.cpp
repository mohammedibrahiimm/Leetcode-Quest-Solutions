class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int>dist;
        vector<vector<vector<int>>>graph(n);
        for (auto &it : edges) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        auto BFS = [&](int node)->int {
            dist.assign(n, 1e9);
            queue<int>q; q.push(node);
            dist[node] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto &it : graph[cur]) {
                    if (dist[it[0]] > dist[cur] + it[1]) {
                        dist[it[0]] = dist[cur] + it[1];
                        q.push(it[0]);
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += dist[i] <= distanceThreshold;
            return cnt;
        };
        int ans = -1, cnt = INT_MAX;
        for (int i = 0; i < n; i++) {
            int val = BFS(i);
            if (val < cnt) {
                ans = i, cnt = val;
            } else if (val == cnt) {
                ans = i;
            }
        }
        return ans;
    }
};