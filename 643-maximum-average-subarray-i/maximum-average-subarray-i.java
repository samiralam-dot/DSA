class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double ans = Double.NEGATIVE_INFINITY;
        int i = 0, j = 0;
        int sum = 0;
        int n = nums.length;

        while (j < n) {
            sum += nums[j];

            if (j - i + 1 > k) {
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k) {
                ans = Math.max(ans, sum / (double) k);
            }

            j++;
        }

        return ans;
    }
}