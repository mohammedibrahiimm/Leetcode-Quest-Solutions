#define all(v)    v.begin(),v.end()

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int s = -1, e = -1;
        sort(all(intervals));
        vector<vector<int>>ans;
        for (auto &it : intervals) {
            if (it[0] > e) {
                if (~s)ans.push_back({s, e}); s = it[0], e = it[1];
            }
            else
                e = max(e, it[1]);
        }
        ans.push_back({s, e});

        return ans;
    }
};