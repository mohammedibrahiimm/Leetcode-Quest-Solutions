class Solution {
public:
    vector<vector<int> > dp;
    int mod = 1e9 + 7;

    int numWays(int n, int k) {
        if (k == 0 || k > n) return 0;
        if (n <= 2) return 1;

        if (dp[n][k] != -1) return dp[n][k];

        long long ans = 0;

        ans = (ans + numWays(n - 1, k - 1)) % mod;

        // select any of the n - 1 sticks that are not the intest
        ans = (ans + (1ll * (n - 1) * numWays(n - 1, k))) % mod;

        return dp[n][k] = ans;
    }

    int rearrangeSticks(int n, int k) {
        dp = vector<vector<int> >(n + 1, vector<int>(k + 1, -1));
        return numWays(n, k);
    }
};