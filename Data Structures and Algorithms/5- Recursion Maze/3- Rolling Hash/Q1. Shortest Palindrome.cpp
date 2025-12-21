#define all(v)    v.begin(),v.end()

class DoubleHash {
private:
    static const int MOD1 = 1000000087;
    static const int MOD2 = 1000000033;
    static const int P1 = 31;
    static const int P2 = 37;

    int n;
    vector<int> pw1, pw2, inv1, inv2, pref1, pref2;

    int add(int a, int b, int MOD) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    int mul(long long a, long long b, int MOD) {
        return (a * b) % MOD;
    }

    int power(int a, int b, int MOD) {
        int res = 1;
        while (b) {
            if (b & 1) res = mul(res, a, MOD);
            a = mul(a, a, MOD);
            b >>= 1;
        }
        return res;
    }

    void precompute() {
        pw1[0] = pw2[0] = 1;
        inv1[0] = inv2[0] = 1;

        int invP1 = power(P1, MOD1 - 2, MOD1);
        int invP2 = power(P2, MOD2 - 2, MOD2);

        for (int i = 1; i <= n; i++) {
            pw1[i] = mul(pw1[i - 1], P1, MOD1);
            pw2[i] = mul(pw2[i - 1], P2, MOD2);

            inv1[i] = mul(inv1[i - 1], invP1, MOD1);
            inv2[i] = mul(inv2[i - 1], invP2, MOD2);
        }
    }

public:
    // constructor
    DoubleHash(const string &s) {
        n = s.size();
        pw1.resize(n + 1);
        pw2.resize(n + 1);
        inv1.resize(n + 1);
        inv2.resize(n + 1);
        pref1.resize(n + 1);
        pref2.resize(n + 1);

        precompute();

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;

            pref1[i + 1] = add(pref1[i],
                               mul(val, pw1[i], MOD1), MOD1);

            pref2[i + 1] = add(pref2[i],
                               mul(val, pw2[i], MOD2), MOD2);
        }
    }

    // hash of full string
    pair<int, int> get_hash() {
        return {pref1[n], pref2[n]};
    }

    // hash of substring [l, r] (1-based)
    pair<int, int> get_hash_range(int l, int r) {
        int x1 = add(pref1[r], MOD1 - pref1[l - 1], MOD1);
        int x2 = add(pref2[r], MOD2 - pref2[l - 1], MOD2);

        x1 = mul(x1, inv1[l - 1], MOD1);
        x2 = mul(x2, inv2[l - 1], MOD2);

        return {x1, x2};
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        DoubleHash Front(s);
        reverse(all(s));
        DoubleHash Back(s);
        const int n = s.size();
        int mx = -1;
        for (int i = 0; i < n; i++) {
            pair<int, int>Fsub = Front.get_hash_range(1, i + 1);
            int rem = n - i;
            pair<int, int>Bsub = Back.get_hash_range(rem, n);
            if (Fsub == Bsub) {
                mx = max(mx, i);
            }
        }
        reverse(all(s));
        string ans;
        for (int i = n - 1; i > mx; i--) {
            ans += s[i];
        }
        ans += s;
        return ans;
    }
};