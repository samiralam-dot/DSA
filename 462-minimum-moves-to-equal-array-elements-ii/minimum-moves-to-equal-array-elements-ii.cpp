class Solution {
public:

    #define ll long long

    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int med = nums[n/2];

        ll ans = 0;

        for(auto x : nums){
            ans += abs(x - med);
        }

        return ans;
    }
};