class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long>v;
        long long cur = 0;
        while (cur * cur <= c) {
            v.push_back(cur * cur);
            long long val = c - cur * cur;
            if (binary_search(v.begin(), v.end(), val))
                return 1;
            cur++;
        }
        return 0;
    }
};