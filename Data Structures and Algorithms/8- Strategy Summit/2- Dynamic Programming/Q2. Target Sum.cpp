class Solution {
public:
    map<pair<int, int>, int>mp;
    int findTargetSumWays(vector<int>& nums, int target, int i = 0) {
        if (i == nums.size())return target == 0;
        if (mp.count(make_pair(i, target)))
            return mp[ {i, target}];
        int &ret = mp[ {i, target}];
        ret += findTargetSumWays(nums, target + nums[i], i + 1);
        ret += findTargetSumWays(nums, target - nums[i], i + 1);
        return ret;
    }
};