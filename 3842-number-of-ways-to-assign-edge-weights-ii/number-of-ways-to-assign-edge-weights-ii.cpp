
class Solution {
public:
    const int MOD = 1e9 + 7;
    int LOG = 17;

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<vector<int>> up(n + 1, vector<int>(LOG + 1));
        vector<int> depth(n + 1, 0);

        function<void(int,int)> dfs = [&](int u, int p) {
            up[u][0] = p;

            for(int j = 1; j <= LOG; j++) {
                up[u][j] = up[up[u][j - 1]][j - 1];
            }

            for(int v : adj[u]) {
                if(v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        };

        dfs(1, 0);

        auto lca = [&](int u, int v) {
            if(depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for(int j = LOG; j >= 0; j--) {
                if(diff & (1 << j)) {
                    u = up[u][j];
                }
            }

            if(u == v) return u;

            for(int j = LOG; j >= 0; j--) {
                if(up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };

        vector<int> ans;
        vector<int> pw(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            pw[i] = 1LL * pw[i - 1] * 2 % MOD;
        }

        for(auto &q : queries) {
            int u = q[0], v = q[1];
            int w = lca(u, v);

            int d = depth[u] + depth[v] - 2 * depth[w];

            if(d == 0) ans.push_back(0);
            else ans.push_back(pw[d - 1]);
        }

        return ans;
    }
};
