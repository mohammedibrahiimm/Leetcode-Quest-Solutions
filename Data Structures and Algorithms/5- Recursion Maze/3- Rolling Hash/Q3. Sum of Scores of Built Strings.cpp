struct Hash64 {
    static const uint64_t BASE = 1315423911ULL;
    vector<uint64_t> pw, pref;
    int n;

    Hash64(const string &s) {
        n = s.size();
        pw.resize(n + 1);
        pref.resize(n + 1);
        pw[0] = 1;

        for (int i = 0; i < n; i++) {
            pw[i + 1] = pw[i] * BASE;
            pref[i + 1] = pref[i] * BASE + (s[i] + 1);
        }
    }

    uint64_t get(int l, int r) { // 1-based
        return pref[r] - pref[l - 1] * pw[r - l + 1];
    }
};

class Solution {
public:
    long long sumScores(string s) {
        Hash64 hash(s);
        const int n = s.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int low = 0, high = i, mid, p = 0;
            while (low <= high) {
                mid = (low + high) >> 1;
                if (hash.get(1, mid + 1) == hash.get(n - i, n - i + mid)) {
                    low = mid + 1, p = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans += p;
        }
        return ans;
    }
};