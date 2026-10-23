class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001];

    int solve(int i, int j, vector<string>& words, string& target,
              vector<vector<int>>& freq) {
        if (i == target.size()) return 1;
        if (j == words[0].size()) return 0;

        int &ans = dp[i][j];
        if (ans != -1) return ans;

        long long res = solve(i, j + 1, words, target, freq);

        res += 1LL * freq[j][target[i] - 'a'] *
               solve(i + 1, j + 1, words, target, freq);

        return ans = res % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>> freq(n, vector<int>(26, 0));

        for (auto &word : words) {
            for (int j = 0; j < n; j++) {
                freq[j][word[j] - 'a']++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, words, target, freq);
    }
};