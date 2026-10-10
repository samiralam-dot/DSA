class Solution {
public:
    bool check(string &a, string &b) {
        int cnt = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
            if (cnt > 2) return false;
        }

        return cnt == 0 || cnt == 2;
    }

    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};