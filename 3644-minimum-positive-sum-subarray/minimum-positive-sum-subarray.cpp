class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<long long> pref(n+1, 0);

        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + nums[i];
        }

        multiset<long long> st;
        int mn = INT_MAX;

        for(int j=l; j<=n; j++){

            st.insert(pref[j-l]);

            if(j-r-1 >= 0){
                auto it = st.find(pref[j-r-1]);
                if(it != st.end()) st.erase(it);
            }

            auto it = st.lower_bound(pref[j]);

            if(it != st.begin()){
                it--;
                mn = min(mn, (int)(pref[j]-*it));
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }
};