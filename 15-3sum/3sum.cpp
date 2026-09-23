class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            unordered_map<int,int> m;

            for(int j = i+1; j < n; j++) {
                int need = -(nums[i] + nums[j]);

                if(m.find(need) != m.end()) {
                    ans.push_back({nums[i], need, nums[j]});

                    while(j+1 < n && nums[j] == nums[j+1])
                        j++;
                }

                m[nums[j]] = 1;
            }
        }

        return ans;
    }
};