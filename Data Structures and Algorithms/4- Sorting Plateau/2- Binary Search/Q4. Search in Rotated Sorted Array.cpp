class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, p = -1;
        int start = nums[0];
        while (low <= high) {
            mid = (low + high) >> 1;
            if (nums[mid] < start)
                high = mid - 1;
            else
                low = mid + 1, p = mid;
        }
        int ans = -1;
        if (target >= start) {
            low = 0, high = p;
            while (low <= high) {
                mid = (low + high) >> 1;
                if (nums[mid] > target)
                    high = mid - 1;
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                    return mid;
            }
        } else {
            low = p + 1, high = nums.size() - 1;
            while (low <= high) {
                mid = (low + high) >> 1;
                if (nums[mid] > target)
                    high = mid - 1;
                else if (nums[mid] < target)
                    low = mid + 1;
                else
                    return mid;
            }
        }
        return -1;
    }
};