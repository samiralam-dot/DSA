class Solution {
    public int maxSubArray(int[] nums) {
        int ans=Integer.MIN_VALUE;
        int cur=0;
        for(int x:nums){
            cur=Math.max(cur+x,x);
            
            
            ans=Math.max(ans,cur);
        }
  return ans;
        
    }
}