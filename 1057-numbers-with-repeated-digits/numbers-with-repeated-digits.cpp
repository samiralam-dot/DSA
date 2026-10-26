class Solution {
public:
map<vector<int>,int>m;

    int solve(int pos, int t, int st, int mask, bool flg, string &s) {
        if (pos == s.size()) {
            return flg;
        }
        vector<int>key={pos,t,st,mask,flg};
        if(m[key]>0)return m[key];

        int ans = 0;
        int l = t ? s[pos] - '0' : 9;

        for (int d = 0; d <= l; d++) {
            int nt = t && (d == s[pos] - '0');

            if (!st && d == 0) {
                ans += solve(pos + 1, nt, 0, mask, flg, s);
            }
            else {
                if (mask & (1 << d)) {
                    ans += solve(pos + 1, nt, 1, mask, true, s);
                }
                else {
                    ans += solve(pos + 1, nt, 1,
                                 mask | (1 << d), flg, s);
                }
            }
        }

        return m[key]= ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        return solve(0, 1, 0, 0, false, s);
    }
};