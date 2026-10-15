
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        vector<int> suf(n);
        suf[n - 1] = shifts[n - 1] % 26;

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = (suf[i + 1] + shifts[i]) % 26;
        }

        for (int i = 0; i < n; i++) {
            int val = s[i] - 'a';
            val = (val + suf[i]) % 26;
            s[i] = char(val + 'a');
        }

        return s;
    }
};