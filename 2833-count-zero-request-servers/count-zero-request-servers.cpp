class Solution {
public:
    vector<int> countServers(int y, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        int n = queries.size();
        vector<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(y + 1, 0);
        vector<int> ans(n, 0);

        int l = 0, r = 0;
        int active = 0;
        int m = logs.size();

        for(auto [t, idx] : q) {

            while(r < m && logs[r][1] <= t) {
                int id = logs[r][0];

                if(freq[id] == 0) active++;
                freq[id]++;

                r++;
            }

            while(l < r && logs[l][1] < t - x) {
                int id = logs[l][0];

                freq[id]--;
                if(freq[id] == 0) active--;

                l++;
            }

            ans[idx] = y - active;
        }

        return ans;
    }
};