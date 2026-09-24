class Solution {
public:
    int partitionString(string s) {
        vector<bool> used(26, false);
        int ans = 1;

        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if(used[idx]) {
                ans++;
                fill(used.begin(), used.end(), false);
            }

            used[idx] = true;
        }

        return ans;
    }
};