class Solution {
public:
    map<int, int> m;

    void update(int x) {
        x += 100001;

        while (x <= 200001) {
            m[x]++;
            x += (x & -x);
        }
    }

    int query(int x) {
        x += 100001;
        int ans = 0;

        while (x > 0) {
            ans += m[x];
            x -= (x & -x);
        }

        return ans;
    }

    long long numberOfPairs(vector<int>& nums1,
                            vector<int>& nums2, int diff) {
        long long ans = 0;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            int d = nums1[i] - nums2[i];

            ans += query(d + diff);
            update(d);
        }

        return ans;
    }
};