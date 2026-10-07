class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> st;
        
        for (auto x : nums)
            st.insert(x);

        int ans = 0;

        for (auto x : nums) {
            auto it = st.find(x);

            if (it == st.end())
                continue;

            st.erase(it); 

            auto it2 = st.find(k - x);

            if (it2 != st.end()) {
                ans++;
                st.erase(it2); 
            }
        }

        return ans;
    }
};