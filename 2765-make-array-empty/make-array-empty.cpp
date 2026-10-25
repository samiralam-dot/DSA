class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i + 1});

        sort(a.begin(), a.end());

        vector<int> bit(n + 1, 0);

        auto update = [&](int i) {
            while (i <= n) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        };

        long long ans = 0;
        int prev = 1;

        for (auto [val, idx] : a) {
            if (idx >= prev) {
                ans += idx - prev + 1 - (query(idx) - query(prev - 1));
            } else {
                ans += n - prev + 1 - (query(n) - query(prev - 1));
                ans += idx - query(idx);
            }

            update(idx);
            prev = idx + 1;
            if (prev > n) prev = 1;
        }

        return ans;
    }
};