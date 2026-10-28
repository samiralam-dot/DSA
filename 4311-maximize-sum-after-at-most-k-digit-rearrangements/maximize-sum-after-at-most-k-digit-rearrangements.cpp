class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> gain(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            sort(s.rbegin(), s.rend());

            int x = stoi(s);
            gain[i] = x - nums[i];
            ans += nums[i];
        }

        sort(gain.rbegin(), gain.rend());

        for (int i = 0; i < k; i++) {
            ans += gain[i];
        }

        return ans;
    }
};