class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                set<long long> s;

                for(int k = j + 1; k < n; k++) {
                    long long need = (long long)target 
                                   - nums[i] - nums[j] - nums[k];

                    if(s.find(need) != s.end()) {
                        vector<int> temp = {
                            nums[i], nums[j], nums[k], (int)need
                        };
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    s.insert(nums[k]);
                }
            }
        }

        for(auto x : st)
            ans.push_back(x);

        return ans;
    }
};