#define all(v)    v.begin(),v.end()

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long curSum(accumulate(all(target), 0ll));
        priority_queue<long long>pq(all(target));
        while (pq.top() != 1) {
            int cur = pq.top(); pq.pop();
            if (curSum - cur == 1)return true;
            long long x = curSum == cur ? cur : cur % (curSum - cur);
            curSum = curSum - cur + x;

            if (x == 0 || x == cur) return false;
            else pq.push(x);
        }
        return true;
    }
};