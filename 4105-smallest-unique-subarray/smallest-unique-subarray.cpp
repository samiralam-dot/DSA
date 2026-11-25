
class Solution {
public:
    using ll = long long;

    const ll mod1 = 1000000007;
    const ll mod2 = 1000000009;
    const ll p1 = 31;
    const ll p2 = 37;

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<ll> h1(n+1), h2(n+1);
        vector<ll> pw1(n+1, 1), pw2(n+1, 1);

        for(int i = 0; i < n; i++) {

            h1[i+1] = (h1[i] * p1 + nums[i]) % mod1;
            h2[i+1] = (h2[i] * p2 + nums[i]) % mod2;

            pw1[i+1] = pw1[i] * p1 % mod1;
            pw2[i+1] = pw2[i] * p2 % mod2;
        }

        auto getHash = [&](int l, int r) {

            ll x = (h1[r] - h1[l] * pw1[r-l] % mod1 + mod1) % mod1;
            ll y = (h2[r] - h2[l] * pw2[r-l] % mod2 + mod2) % mod2;

            return make_pair(x, y);
        };

        auto check = [&](int k) {

            map<pair<ll,ll>, int> mp;

            for(int i = 0; i+k <= n; i++) {
                mp[getHash(i, i+k)]++;
            }

            for(auto &it : mp) {
                if(it.second == 1)
                    return true;
            }

            return false;
        };

        int l = 1, r = n;
        int ans = n;

        while(l <= r) {

            int mid = l + (r-l)/2;

            if(check(mid)) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        return ans;
    }
};
