class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<long long> sum(4 * n), sq(4 * n), lazy(4 * n);
        vector<int> last(100001, -1);

        function<void(int,int,int,int,int)> update =
        [&](int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                long long len = r - l + 1;

                sq[node] = (sq[node] + 2 * sum[node] + len) % mod;
                sum[node] = (sum[node] + len) % mod;
                lazy[node]++;

                return;
            }

            int mid = (l + r) / 2;

            if (lazy[node]) {
                long long v = lazy[node];

                for (int child : {2 * node + 1, 2 * node + 2}) {
                    int len = (child == 2 * node + 1)
                            ? mid - l + 1 : r - mid;

                    sq[child] = (sq[child] + 2 * v * sum[child]
                                + v * v * len) % mod;

                    sum[child] = (sum[child] + v * len) % mod;
                    lazy[child] += v;
                }

                lazy[node] = 0;
            }

            update(2 * node + 1, l, mid, ql, qr);
            update(2 * node + 2, mid + 1, r, ql, qr);

            sum[node] = (sum[2 * node + 1] + sum[2 * node + 2]) % mod;
            sq[node] = (sq[2 * node + 1] + sq[2 * node + 2]) % mod;
        };

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            update(0, 0, n - 1, prev + 1, i);

            ans = (ans + sq[0]) % mod;
            last[nums[i]] = i;
        }

        return ans;
    }
};