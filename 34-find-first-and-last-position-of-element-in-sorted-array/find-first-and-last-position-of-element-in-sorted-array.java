
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int idx1 = -1, idx2 = -1;
        int n = nums.length;
        int l = 0, h = n - 1;

        // Lower bound: first index >= target
        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] >= target) {
                idx1 = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (idx1 == -1 || nums[idx1] != target) {
            return new int[]{-1, -1};
        }

        l = 0;
        h = n - 1;

        // Upper bound: first index > target
        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] > target) {
                idx2 = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        if (idx2 == -1) {
            idx2 = n;
        }

        idx2--;

        return new int[]{idx1, idx2};
    }
}
