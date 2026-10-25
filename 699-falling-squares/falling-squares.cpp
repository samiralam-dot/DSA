class Solution {
public:
    map<long long, int> seg, lazy;

    void push(long long idx) {
        if (lazy[idx] == 0) return;

        long long left = idx * 2;
        long long right = idx * 2 + 1;
        int val = lazy[idx];

        seg[left] = max(seg[left], val);
        seg[right] = max(seg[right], val);

        lazy[left] = max(lazy[left], val);
        lazy[right] = max(lazy[right], val);

        lazy[idx] = 0;
    }

    int query(long long idx, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;

        if (l <= s && e <= r)
            return seg[idx];

        push(idx);

        int mid = s + (e - s) / 2;

        return max(
            query(idx * 2, s, mid, l, r),
            query(idx * 2 + 1, mid + 1, e, l, r)
        );
    }

    void update(long long idx, int s, int e,
                int l, int r, int val) {
        if (r < s || e < l) return;

        if (l <= s && e <= r) {
            seg[idx] = max(seg[idx], val);
            lazy[idx] = max(lazy[idx], val);
            return;
        }

        push(idx);

        int mid = s + (e - s) / 2;

        update(idx * 2, s, mid, l, r, val);
        update(idx * 2 + 1, mid + 1, e, l, r, val);

        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        int mx = 0;

        for (auto &p : positions) {
            int l = p[0];
            int r = p[0] + p[1] - 1;

            int h = query(1, 0, 1000000000, l, r) + p[1];

            update(1, 0, 1000000000, l, r, h);

            mx = max(mx, h);
            ans.push_back(mx);
        }

        return ans;
    }
};