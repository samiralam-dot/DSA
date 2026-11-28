
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = n;

        // Count frequency of every factor
        vector<int> freq(mx + 1, 0);

        int mn = INT_MAX;

        for (auto &x : items) {
            freq[x[0]]++;
            mn = min(mn, x[1]);
        }

        // Calculate gain using multiples
        vector<int> gain(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                gain[i] += freq[j];
            }

            if (freq[i] > 0)
                gain[i]--;
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const auto &a, const auto &b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        // Buy special copies first (value = 2)
        for (auto &x : items) {
            long long price = x[1];
            int f = x[0];

            if (price > 2LL * mn)
                break;

            if (gain[f] == 0)
                continue;

            long long cnt = min(
                (long long)gain[f],
                rem / price
            );

            ans += 2LL * cnt;
            rem -= cnt * price;
        }

        // Buy ordinary copies (value = 1)
        ans += rem / mn;

        return (int)ans;
    }
};
