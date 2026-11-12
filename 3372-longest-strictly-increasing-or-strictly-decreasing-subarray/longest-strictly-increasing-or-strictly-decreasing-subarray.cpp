
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        int st = 0;
        int j = 1;

        int inc = 1, dec = 1;

        while(j < n) {
            if(nums[j] > nums[j-1]) {
                inc++;
                dec = 1;
            }
            else if(nums[j] < nums[j-1]) {
                dec++;
                inc = 1;
            }
            else {
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
            j++;
        }

        return ans;
    }
};
