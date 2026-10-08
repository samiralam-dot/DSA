class Solution {
public:

    #define ll long long
    const ll MOD = 1000000007;

    vector<vector<int>> adj;

    ll power(ll a, ll b) {
        ll res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        adj.resize(n);

        // Build tree
        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> vis(n, 0);

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = 1;

        int mx = 0;

        while (!q.empty()) {

            auto [node, dist] = q.front();
            q.pop();

            mx = max(mx, dist);

            for (int next : adj[node]) {

                if (!vis[next]) {
                    vis[next] = 1;
                    q.push({next, dist + 1});
                }
            }
        }

  
        if (mx == 0)
            return 0;

        return power(2, mx - 1);
    }
};