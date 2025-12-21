class Solution {
    vector<string>v;
public:
    void solve(int i, int n, string s, char p) {
        if (i == n) {
            v.push_back(s);
        } else {
            for (int c = 0; c <= 2; c++) {
                char C = c + 'a';
                if (p != c) {
                    solve(i + 1, n, s + C, c);
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        solve(0, n, "", -1);
        if (k > v.size()) return "";
        return v[k - 1];
    }
};