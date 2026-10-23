class Solution {
public:
    int solve(int i, int st, vector<string>& nums, string& s) {
        if (i == s.size()) return 1;

        int ans = 0;

        for (auto x : nums) {
            int d = x[0] - '0';
            int limit = s[i] - '0';

            if (st) {
                if (d < limit) {
                    ans += pow(nums.size(), s.size() - i - 1);
                }
                else if (d == limit) {
                    ans += solve(i + 1, 1, nums, s);
                }
            }
            else {
                ans += solve(i + 1, 0, nums, s);
            }
        }

        return ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int ans = solve(0, 1, digits, s);

        for (int len = 1; len < s.size(); len++) {
            ans += pow(digits.size(), len);
        }

        return ans;
    }
};