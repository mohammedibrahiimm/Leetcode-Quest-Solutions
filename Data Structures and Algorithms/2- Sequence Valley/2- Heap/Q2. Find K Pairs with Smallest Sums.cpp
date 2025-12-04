class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        const int n = nums1.size(), m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        map<vector<int>, bool>mp;
        while (ans.size() < k) {
            vector<int>bestSum = pq.top(); pq.pop();
            int idx1 = bestSum[1], idx2 = bestSum[2];
            ans.push_back({nums1[idx1], nums2[idx2]});

            if (idx1 + 1 < n && !mp.count(vector<int> {idx1 + 1, idx2}))
                pq.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2}), mp[vector<int> {idx1 + 1, idx2}] = true;;
            if (idx2 + 1 < m && !mp.count(vector<int> {idx1, idx2 + 1}))
                pq.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1}), mp[vector<int> {idx1, idx2 + 1}] = true;;
        }
        return ans;
    }
};
