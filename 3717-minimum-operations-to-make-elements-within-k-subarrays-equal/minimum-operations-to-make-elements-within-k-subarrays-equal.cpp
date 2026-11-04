
class Solution {
public:
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) {
            this->n = n;
            bit.resize(n+1, 0);
        }

        void update(int i, long long val) {
            while(i <= n) {
                bit[i] += val;
                i += i&-i;
            }
        }

        long long query(int i) {
            long long ans = 0;

            while(i > 0) {
                ans += bit[i];
                i -= i&-i;
            }

            return ans;
        }

        int kth(int k) {
            int pos = 0;

            for(int i = 1 << 17; i > 0; i >>= 1) {
                if(pos+i <= n && bit[pos+i] < k) {
                    k -= bit[pos+i];
                    pos += i;
                }
            }

            return pos+1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();

        BIT cnt(m), sum(m);

        long long total = 0;

        auto add = [&](int val, int f) {
            int id = lower_bound(v.begin(), v.end(), val)-v.begin()+1;

            cnt.update(id, f);
            sum.update(id, 1LL*val*f);
            total += 1LL*val*f;
        };

        vector<long long> cost(n-x+1);

        for(int i=0; i<n; i++) {
            add(nums[i], 1);

            if(i >= x) {
                add(nums[i-x], -1);
            }

            if(i >= x-1) {
                int id = cnt.kth((x+1)/2);
                long long med = v[id-1];

                long long c = cnt.query(id);
                long long s = sum.query(id);

                cost[i-x+1] = med*c-s + (total-s)-med*(x-c);
            }
        }

        const long long INF = 1e18;

        vector<long long> dp(n+1, 0), ndp(n+1, INF);

        for(int j=1; j<=k; j++) {
            fill(ndp.begin(), ndp.end(), INF);

            for(int i=1; i<=n; i++) {
                ndp[i] = ndp[i-1];

                if(i >= x) {
                    ndp[i] = min(ndp[i],
                                 dp[i-x]+cost[i-x]);
                }
            }

            dp = ndp;
        }

        return dp[n];
    }
};
