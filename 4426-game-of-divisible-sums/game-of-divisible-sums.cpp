
class Solution {
public:

    long long solve(int i, int t, vector<int>& nums,
                    vector<vector<long long>>& dp) {

        if(i >= nums.size()) return 0;

        if(dp[i][t] != LLONG_MIN) return dp[i][t];

        long long ans;
        long long val = nums[i];

        int nt = (val % 3 == 0 ? !t : t);

        long long x;
        if(t == 1)
            x = val + solve(i + 1, nt, nums, dp);
        else
            x = -val + solve(i + 1, nt, nums, dp);

        if(t == 1) ans = x;
        else ans = x;

      
        if(i + 1 < nums.size()) {

            val += nums[i + 1];

            nt = (val % 3 == 0 ? !t : t);

            if(t == 1)
                x = val + solve(i + 2, nt, nums, dp);
            else
                x = -val + solve(i + 2, nt, nums, dp);

            if(t == 1) ans = max(ans, x);
            else ans = min(ans, x);
        }

        return dp[i][t] = ans;
    }

    long long maxDifference(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long long>> dp(
            n, vector<long long>(2, LLONG_MIN)
        );

        return solve(0, 1, nums, dp);
    }
};
