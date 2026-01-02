class Solution {
public:
    map<string, bool>mp;
    vector<vector<int>>dp;
    bool solve(int i, int prev, string &s) {
        if (i == s.size())return prev == s.size();
        int &ret = dp[i][prev];
        if (~ret)return ret;
        ret = 0;
        string cur = s.substr(prev, i - prev + 1);
        if (mp.count(cur)) {
            ret |= solve(i + 1, i + 1, s);
        }
        ret |= solve(i + 1, prev, s);
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        for (auto &x : wordDict)mp[x] = 1;
        return solve(0, 0, s);
    }
};