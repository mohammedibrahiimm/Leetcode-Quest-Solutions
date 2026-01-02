class Solution {
public:
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int dp[100] = {}, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i - 1; j++)
                dp[i] = max(dp[j] + nums[i], dp[i]);
            dp[i] = max(dp[i], nums[i]);
        }
        return *max_element(dp, dp + 100);
    }
};