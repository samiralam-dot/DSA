class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        vector<long long> mp(1024, 0);

        int mask = 0;
        mp[0] = 1;

        for (char c : word) {
            mask ^= (1 << (c - 'a'));

            ans += mp[mask];

            for (int i = 0; i < 10; i++) {
                ans += mp[mask ^ (1 << i)];
            }

            mp[mask]++;
        }

        return ans;
    }
};