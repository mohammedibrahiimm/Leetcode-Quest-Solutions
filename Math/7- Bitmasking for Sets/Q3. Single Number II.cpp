class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int cnt[32] = {};
        for (auto &it : nums) {
            for (int b = 0; b < 32; b++) {
                if (it & (1 << b)) {
                    cnt[b]++;
                }
            }
        }
        for (int b = 0; b < 32; b++)
            ans |= (cnt[b] % 3 ? 1 << b : 0);
        return ans;
    }
};