class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=INT_MAX;
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<nums.size();i++){
            if(sorted[i]!=nums[i]){
                ans&=nums[i];
            }
        }
   return ans==INT_MAX?0:ans;
        
    }
};