class Solution {
public:

    long long ans = 0;
    int seats;

    long long dfs(int node, int parent, vector<vector<int>>& lis) {

        long long people = 1;

        for (auto x : lis[node]) {

            if (x == parent)
                continue;

            long long childPeople = dfs(x, node, lis);

            // Cars needed from child -> node
            long long cars = (childPeople + seats - 1) / seats;

            ans += cars;

            people += childPeople;
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seat) {

        seats = seat;

        int n = roads.size() + 1;

        vector<vector<int>> lis(n);

        for (auto &x : roads) {
            int u = x[0];
            int v = x[1];

            lis[u].push_back(v);
            lis[v].push_back(u);
        }

        dfs(0, -1, lis);

        return ans;
    }
};