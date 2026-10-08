class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        map<int, int> mp;

        for (auto &v : intervals) {
            mp[v[0]]++;       
            mp[v[1] + 1]--;   
        }

        int overlap = 0;
        int ans = 0;

        for (auto &[x, val] : mp) {
            overlap += val;
            ans = max(ans, overlap);
        }

        return ans;
    }
};