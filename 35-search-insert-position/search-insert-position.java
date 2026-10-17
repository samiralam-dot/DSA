class Solution {
    public int searchInsert(int[] nums, int target) {
        int idx = nums.length;
        int l = 0, h = nums.length - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] >= target) {
                idx = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return idx;
    }
}