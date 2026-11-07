
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> avail;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;

        for(int i = 0; i < n; i++)
            avail.push({servers[i], i});

        vector<int> ans(m);
        long long time = 0;

        for(int i = 0; i < m; i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && busy.top()[0] <= time) {
                auto v = busy.top();
                busy.pop();
                avail.push({v[1], v[2]});
            }

            if(avail.empty()) {
                time = busy.top()[0];

                while(!busy.empty() && busy.top()[0] <= time) {
                    auto v = busy.top();
                    busy.pop();
                    avail.push({v[1], v[2]});
                }
            }

            auto [w, idx] = avail.top();
            avail.pop();

            ans[i] = idx;
            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};
