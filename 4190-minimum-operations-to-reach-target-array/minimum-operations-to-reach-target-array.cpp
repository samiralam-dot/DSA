
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int ans = 0;

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                st.insert(nums[i]);
            }
        }

        return st.size();
    }
};