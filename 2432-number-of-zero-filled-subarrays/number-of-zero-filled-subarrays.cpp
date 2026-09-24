class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;
        long long len = 0;

        for(auto x : nums) {

            if(x == 0) {
                len++;
            }
            else {
                ans += len * (len + 1) / 2;
                len = 0;
            }
        }

  
        ans += len * (len + 1) / 2;

        return ans;
    }
};