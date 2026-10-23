
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;

        for(int top = 0; top < n; top++) {
            vector<int> sum(m, 0);

            for(int bottom = top; bottom < n; bottom++) {
                for(int col = 0; col < m; col++) {
                    sum[col] += matrix[bottom][col];
                }

                unordered_map<int, int> mp;
                mp[0] = 1;
                int pref = 0;

                for(int col = 0; col < m; col++) {
                    pref += sum[col];

                    if(mp.count(pref - target)) {
                        ans += mp[pref - target];
                    }

                    mp[pref]++;
                }
            }
        }

        return ans;
    }
};
