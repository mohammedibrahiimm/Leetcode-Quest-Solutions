class Solution {
public:
    int dp[110][110][210];
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3) {
        if (j > s2.size())return 0;
        if (i > s1.size())return 0;
        if (k == s3.size())return 1;
        int &ret = dp[i][j][k];
        if (~ret)return ret;
        ret = 0;
        if (i < s1.size() && j < s2.size()) {
            if (s1[i] == s3[k] && s2[j] == s3[k])
                ret |= (solve(i + 1, j, k + 1, s1, s2, s3) | solve(i, j + 1, k + 1, s1, s2, s3));
            else if (s1[i] == s3[k])
                ret |= solve(i + 1, j, k + 1, s1, s2, s3);
            else if (s2[j] == s3[k])
                ret |= solve(i, j + 1, k + 1, s1, s2, s3);
        } else if (i < s1.size()) {
            if (s1[i] == s3[k])
                ret |= solve(i + 1, j, k + 1, s1, s2, s3);
        } else if (j < s2.size()) {
            if (s2[j] == s3[k])
                ret |= solve(i, j + 1, k + 1, s1, s2, s3);
        }
        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof dp);
        if (s1.size() + s2.size() != s3.size())return 0;
        return solve(0, 0, 0, s1, s2, s3);
    }
};