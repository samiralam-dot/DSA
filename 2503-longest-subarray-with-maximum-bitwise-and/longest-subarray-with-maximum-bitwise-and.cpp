class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] != mx)
                continue;

            int l = i;
            int r = i;

            while (l >= 0 && nums[l] == mx)
                l--;

            while (r < n && nums[r] == mx)
                r++;

            ans = max(ans, r - l - 1);

            i = r - 1;
        }

        return ans;
    }
};