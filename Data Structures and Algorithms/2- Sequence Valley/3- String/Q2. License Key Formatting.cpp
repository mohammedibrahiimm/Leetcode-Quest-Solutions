#define all(v)    v.begin(),v.end()

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        auto toUpper = [&](const char& c)->char{
            if ('a' <= c && c <= 'z')return c - 'a' + 'A';
            return c;
        };
        string key;
        for (auto &it : s)
            if (it != '-')key += it;
        int cnt = 0;
        reverse(all(key));
        string ans;
        for (auto &it : key) {
            cnt++;
            ans += toUpper(it);
            if (cnt == k)
                ans += "-", cnt = 0;
        }
        if (!ans.empty() && ans.back() == '-')ans.pop_back();
        reverse(all(ans));
        return ans;
    }
};