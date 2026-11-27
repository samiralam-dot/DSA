class Solution {
public:
 
    int maximumSaleItems(vector<vector<int>>& nums, int budget) {
        int ans=0;
        int n=nums.size();
        vector<int>g(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&nums[j][0]%nums[i][0]==0)g[i]++;
            }
        }

        vector<int>dp(budget+1,-1e5);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int c=nums[i][1],gain=g[i];
            for(int j=budget;j>=c;j--){
                dp[j]=max(dp[j],dp[j-c]+gain);
            }
            
        }
        for(int s=0;s<=budget;s++){
            if(dp[s]<0)continue;
            int rem=budget-s;
            ans=max(ans,dp[s]);
            for(int i=0;i<n;i++){
                int extra=rem/nums[i][1];
                ans=max(ans,dp[s]+extra);
            }
        }




        
        return ans;
    
    }
};