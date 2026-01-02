struct segtree {

    vector<int>tree;
    int initValue = 0;

    int merge(int a, int b) {
        return max(a, b);
    }

    segtree(vector<int>& v) {
        int n = (int)v.size();
        while (__builtin_popcount(n) != 1)
            v.push_back(0), n++;
        tree.resize(n << 1, initValue);
        for (int i = 0; i < n; i++)
            tree[i + n] = v[i];
        for (int i = n - 1; i >= 1; i--)
            tree[i] = merge(tree[i << 1] , tree[(i << 1) + 1]);
    }

    int f(int node, int left, int right, int low, int high) {
        if (low <= left && right <= high)
            return tree[node];
        if (right < low || high < left)
            return initValue;
        int mid = (left + right) >> 1;
        int ans = merge(f((node << 1), left, mid, low, high), f((node << 1) + 1, mid + 1, right, low, high));
        return ans;
    }

    void setRange(int node, int left, int right, int low, int high, int v) {
        if (low <= left && right <= high) {
            tree[node] = v;
            return;
        }
        if (right < low || high < left)
            return;
        int mid = (left + right) >> 1;
        setRange((node << 1), left, mid, low, high, v);
        setRange((node << 1) + 1, mid + 1, right, low, high, v);
        tree[node] = merge(tree[node << 1], tree[(node << 1) + 1]);
    }

    void set(int pos, int val) {
        pos += (int)tree.size() >> 1, tree[pos] = val;
        while (pos > 1)
            pos >>= 1, tree[pos] = merge(tree[pos << 1], tree[(pos << 1) + 1]);
    }

};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        segtree st(heights);
        const int n = heights.size();
        vector<int>ans;
        map<int, vector<int>>pos;
        for (int i = 0; i < n; i++)
            pos[heights[i]].push_back(i);
        for (auto &query : queries) {
            int l = query[0], r = query[1];
            if (l > r)swap(l, r);
            if (heights[l] < heights[r] || l == r)ans.push_back(r);
            else {
                int low = r + 1, high = n - 1, mid, p = -1;
                while (low <= high) {
                    mid = (low + high) >> 1;
                    int val = st.f(1, 0, n - 1, r + 1, mid);
                    if (val > heights[l] && val > heights[r]) {
                        high = mid - 1, p = mid;
                    } else {
                        low = mid + 1;
                    }
                }
                ans.push_back(p);
            }
        }
        return ans;
    }
};