class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> st;

        int i = 0;

        for(int j = 0; j < nums.size(); j++) {

        
            auto it = st.lower_bound((long long)nums[j] - valueDiff);

   
            if(it != st.end() && *it <= (long long)nums[j] + valueDiff)
                return true;

    
            st.insert(nums[j]);

           
            if(j - i >= indexDiff) {
                st.erase(nums[i]);
                i++;
            }
        }

        return false;
    }
};