class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), N = n * n;

        vector<int> a(N + 1);
        int x = 1;

        for(int i = n - 1; i >= 0; i--) {
            if((n - 1 - i) % 2 == 0) {
                for(int j = 0; j < n; j++)
                    a[x++] = board[i][j];
            } else {
                for(int j = n - 1; j >= 0; j--)
                    a[x++] = board[i][j];
            }
        }

        vector<int> dp(N + 1, 1e9);
        dp[1] = 0;

        for(int t = 0; t < N; t++) {
            bool change = false;

            for(int u = 1; u < N; u++) {
                if(dp[u] == 1e9) continue;

                for(int d = 1; d <= 6 && u + d <= N; d++) {
                    int v = u + d;

                    if(a[v] != -1)
                        v = a[v];

                    if(dp[v] > dp[u] + 1) {
                        dp[v] = dp[u] + 1;
                        change = true;
                    }
                }
            }

            if(!change) break;
        }

        return dp[N] == 1e9 ? -1 : dp[N];
    }
};