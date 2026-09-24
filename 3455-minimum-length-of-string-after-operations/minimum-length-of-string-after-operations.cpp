class Solution {
public:
    int minimumLength(string s) {

        map<char,int> m;

        for(auto x : s)
            m[x]++;

        int ans = 0;

        for(auto x : m) {
            int f = x.second;

            if(f < 3)
                ans += f;
            else {
                if(f % 2 == 0)
                    ans += 2;
                else
                    ans += 1;
            }
        }

        return ans;
    }
};