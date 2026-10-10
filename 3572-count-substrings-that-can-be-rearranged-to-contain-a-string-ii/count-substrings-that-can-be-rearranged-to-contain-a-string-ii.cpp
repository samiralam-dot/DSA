class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n < m) return 0;

        vector<int> cnt(26, 0);

        for (char c : word2)
            cnt[c - 'a']++;

        int l = 0;
        long long ans = 0;
        int need = m;

        for (int r = 0; r < n; r++) {
            if (cnt[word1[r] - 'a'] > 0)
                need--;

            cnt[word1[r] - 'a']--;

            while (need == 0) {
                ans += n - r;

                cnt[word1[l] - 'a']++;

                if (cnt[word1[l] - 'a'] > 0)
                    need++;

                l++;
            }
        }

        return ans;
    }
};