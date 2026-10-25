class Solution {
public:
    vector<int> bit;

    void update(int i, int n) {
        while (i <= n) {
            bit[i]++;
            i += (i & -i);
        }
    }

    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> v;

        for (int x : nums) {
            v.push_back(x);
            v.push_back(2LL * x);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int sz = v.size();
        bit.assign(sz + 1, 0);

        long long ans = 0;

        for (int i = n - 1; i >= 0; i--) {
           
            int idx = lower_bound(v.begin(), v.end(), (long long)nums[i])
                      - v.begin();

            ans += query(idx);

            int pos = lower_bound(v.begin(), v.end(), (long long)nums[i] * 2)
                      - v.begin() + 1;

            update(pos, sz);
        }

        return ans;
    }
};