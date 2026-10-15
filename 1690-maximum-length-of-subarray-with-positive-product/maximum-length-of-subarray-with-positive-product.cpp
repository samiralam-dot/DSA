
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0;
        int ans = 0;

        for (int x : nums) {
            if (x == 0) {
                pos = 0;
                neg = 0;
            }
            else if (x > 0) {
                pos++;
                if (neg > 0) neg++;
            }
            else {
                int temp = pos;

                pos = (neg > 0) ? neg + 1 : 0;
                neg = temp + 1;
            }

            ans = max(ans, pos);
        }

        return ans;
    }
};
