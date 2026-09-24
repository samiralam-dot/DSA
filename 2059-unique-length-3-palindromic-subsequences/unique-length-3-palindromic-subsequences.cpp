class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++) {

            int l = -1, r = -1;

            for(int i = 0; i < s.size(); i++) {
                if(s[i] == c) {
                    if(l == -1)
                        l = i;

                    r = i;
                }
            }

            if(l == -1 || l == r)
                continue;

            vector<bool> used(26, false);

            for(int i = l + 1; i < r; i++) {
                used[s[i] - 'a'] = true;
            }

            for(int i = 0; i < 26; i++) {
                if(used[i])
                    ans++;
            }
        }

        return ans;
    }
};