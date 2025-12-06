#define all(v)    v.begin(),v.end()

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(all(nums));
        const int n = nums.size();
        int cur = nums[n - 1];
        int cnt = 0, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == cur) {
                cnt++;
            } else {
                ans += cnt, cur = nums[i], cnt++;
            }
        }
        return ans;
    }
};