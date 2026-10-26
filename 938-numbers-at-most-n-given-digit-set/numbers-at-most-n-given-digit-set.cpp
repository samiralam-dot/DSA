class Solution {
public:
map<vector<int>,int>m;
    int solve(int pos, int t, int st, vector<string>& nums, string &s) {
        if (pos == s.size()) return st;

        vector<int>key={pos,t,st};
        if(m[key]>0)return m[key];

        int ans = 0;
        int l = t ? s[pos] - '0' : 9;

        for (auto y : nums) {
            int x = stoi(y);

            if (x > l) continue;

            int nt = t && (x == s[pos] - '0');

            ans += solve(pos + 1, nt, 1, nums, s);
        }

     
        if (!st) {
            ans += solve(pos + 1, 0, 0, nums, s);
        }

        return m[key]= ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        return solve(0, 1, 0, digits, s);
    }
};