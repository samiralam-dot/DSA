class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int l, int r,
             int open, string cur) {

        if (idx == s.size()) {
            if (l == 0 && r == 0 && open == 0)
                ans.insert(cur);
            return;
        }

        char c = s[idx];

        if (c == '(') {

            // remove '('
            if (l > 0)
                dfs(s, idx + 1, l - 1, r, open, cur);

            // keep '('
            dfs(s, idx + 1, l, r, open + 1, cur + c);
        }
        else if (c == ')') {

            // remove ')'
            if (r > 0)
                dfs(s, idx + 1, l, r - 1, open, cur);

            // keep ')'
            if (open > 0)
                dfs(s, idx + 1, l, r, open - 1, cur + c);
        }
        else {
            dfs(s, idx + 1, l, r, open, cur + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int l = 0, r = 0;

        for (char c : s) {
            if (c == '(')
                l++;
            else if (c == ')') {
                if (l > 0)
                    l--;
                else
                    r++;
            }
        }

        dfs(s, 0, l, r, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};