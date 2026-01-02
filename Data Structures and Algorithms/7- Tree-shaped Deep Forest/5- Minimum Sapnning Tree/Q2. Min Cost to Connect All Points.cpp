#define all(v)    v.begin(),v.end()

class point {
public:
    int x, y;
    point(const vector<int>& Point) {
        x = Point[0], y = Point[1];
    }
};

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> Points;
        const int n = points.size();
        DSU dsu(n);
        auto getDist = [&](point a, point b)->int{
            return abs(a.x - b.x) + abs(a.y - b.y);
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                point p1(points[i]), p2(points[j]);
                Points.push_back({getDist(p1, p2), i, j});
            }
        }
        sort(all(Points));
        int ans = 0;
        for (auto &point : Points) {
            if (dsu.uni(point[1], point[2]))continue;
            ans += point[0];
        }
        return ans;
    }
};