class Solution {
    public int maxArea(int[] nums) {
        int n=nums.length;
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            ans=Math.max(ans,Math.min(nums[i],nums[j])*(j-i));
            if(nums[i]<nums[j])i++;
            else j--;
        }
        return ans;
        
    }
}