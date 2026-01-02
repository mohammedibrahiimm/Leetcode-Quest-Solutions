struct DSU {
    vector<int>par, sz;
    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    bool uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y], par[y] = x;
            return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int origin_mst = GetMST(n, edges, -1);
        vector<int> critical, non_critical;
        for (int i = 0; i < edges.size(); ++i) {
            if (origin_mst < GetMST(n, edges, i)) {
                critical.push_back(edges[i][3]);
            } else if (origin_mst == GetMST(n, edges, -1, i)) {
                non_critical.push_back(edges[i][3]);
            }
        }
        return {critical, non_critical};
    }

private:
    int GetMST(const int n, const vector<vector<int>>& edges, int blockedge, int pre_edge = -1) {
        DSU dsu(n);
        int weight = 0;
        if (pre_edge != -1) {
            weight += edges[pre_edge][2];
            dsu.uni(edges[pre_edge][0], edges[pre_edge][1]);
        }
        for (int i = 0; i < edges.size(); ++i) {
            if (i == blockedge) continue;
            const auto& edge = edges[i];
            if (dsu.find(edge[0]) == dsu.find(edge[1])) continue;
            dsu.uni(edge[0], edge[1]);
            weight += edge[2];
        }
        for (int i = 0; i < n; ++i) {
            if (dsu.find(i) != dsu.find(0)) return 1e9 + 7;
        }
        return weight;
    }
};