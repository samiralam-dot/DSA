class Solution {
public:
    int minMoves(vector<int>& nums) {
       int v=*max_element(nums.begin(),nums.end());
       int ans=0;
       for(auto x:nums){
        ans+=abs(x-v);
       }
return ans;
        
    }
};