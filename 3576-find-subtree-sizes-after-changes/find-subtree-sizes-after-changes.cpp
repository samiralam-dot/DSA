
class Solution {
public:

    vector<vector<int>> adj, newAdj;
    vector<int> ans, last;

    void dfs(int node, vector<int>& parent, string &s) {

        int ch = s[node] - 'a';

        int old = last[ch];

        int par = parent[node];

        if(old != -1) {
            par = old;
        }

        if(node != 0) {
            newAdj[par].push_back(node);
        }

        last[ch] = node;

        for(auto child : adj[node]) {
            dfs(child, parent, s);
        }

        last[ch] = old;
    }

    int dfs2(int node) {

        int sz = 1;

        for(auto child : newAdj[node]) {
            sz += dfs2(child);
        }

        return ans[node] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        newAdj.resize(n);
        ans.resize(n, 0);
        last.assign(26, -1);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, parent, s);

        dfs2(0);

        return ans;
    }
};
