
class Solution {
public:
    unordered_map<long long, int> dp;
    vector<int> nxt;

    int solve(int i, int k, vector<vector<int>>& events) {
        if(i >= events.size() || k == 0) return 0;

        long long key = 1LL * i * 1001 + k;

        if(dp.count(key)) return dp[key];

        int take = events[i][2] + solve(nxt[i], k - 1, events);
        int nottake = solve(i + 1, k, events);

        return dp[key] = max(take, nottake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        nxt.resize(n);

        for(int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while(l < r) {
                int mid = l + (r - l) / 2;

                if(events[mid][0] <= events[i][1])
                    l = mid + 1;
                else
                    r = mid;
            }

            nxt[i] = l;
        }

        dp.reserve((size_t)n * min(k, n) + 1);

        return solve(0, k, events);
    }
};
