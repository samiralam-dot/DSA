class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = INF;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;
                    int c = 0;
                    for (int r = 0; r < d; r++) {
                        int a = i + r;
                        int b = j - d + 1 + r;   // last element of group r
                        while (a < b) {
                            c += (s[a] != s[b]);
                            a += d;
                            b -= d;
                        }
                    }
                    best = min(best, c);
                }
                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= min(i / 2, k); p++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {   // segment length >= 2
                    if (dp[j][p - 1] == INF || cost[j][i - 1] == INF) continue;
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};