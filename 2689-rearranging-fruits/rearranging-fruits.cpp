class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> m1, m2;

        for (auto x : basket1) m1[x]++;
        for (auto x : basket2) m2[x]++;

        map<int, int> mp;
        int mn = INT_MAX;

        for (auto x : basket1) mn = min(mn, x);
        for (auto x : basket2) mn = min(mn, x);

        for (auto x : m1) {
            int el = x.first;
            int f1 = x.second;
            int f2 = m2[el];

            if ((f1 + f2) % 2) return -1;

            if (f1 > f2) mp[el] += (f1 - f2) / 2;
        }

        for (auto x : m2) {
            int el = x.first;
            int f2 = x.second;
            int f1 = m1[el];

            if ((f1 + f2) % 2) return -1;

            if (f2 > f1) mp[el] += (f2 - f1) / 2;
        }

        vector<int> v;

        for (auto x : mp) {
            for (int i = 0; i < x.second; i++)
                v.push_back(x.first);
        }

        sort(v.begin(), v.end());

        long long ans = 0;
        int n = v.size();

        for (int i = 0; i < n / 2; i++) {
            ans += min(1LL * v[i], 2LL * mn);
        }

        return ans;
    }
};